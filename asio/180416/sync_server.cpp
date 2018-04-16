#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>

#include <iostream>

typedef boost::shared_ptr<boost::asio::ip::tcp::socket> socket_ptr;

void client_session(socket_ptr sock) {
    while (true) {
        try {
            char data[512];
            size_t len = sock->read_some(boost::asio::buffer(data));
            if (len > 0) {
                boost::asio::write(*sock, boost::asio::buffer("ok", 2));
            }
        } catch (boost::system::system_error e) {
            std::cout << "error code: " << e.code() << " error message: " << e.what() << std::endl;
        }
    }
}

int main(int argc, char *argv[]) {
    boost::asio::io_service service;
    boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address::from_string("127.0.0.1"), 2001);
    boost::asio::ip::tcp::acceptor acc(service, ep);
    while (true) {
        try {
            socket_ptr sock(new boost::asio::ip::tcp::socket(service));
            acc.accept(*sock);
            boost::thread(boost::bind(client_session, sock));
        } catch (boost::system::system_error e) {
            std::cout << "error code: " << e.code() << " error message: " << e.what() << std::endl;
        }
    }

    return 0;
}
