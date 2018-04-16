#include <boost/asio.hpp>

#include <iostream>

int main(int argc, char *argv[]) {
    boost::asio::io_service service;
    boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address::from_string("127.0.0.1"), 2001);
    boost::asio::ip::tcp::socket sock(service);
    try {
        sock.connect(ep);
    } catch (boost::system::system_error e) {
        std::cout << "error code: " << e.code() << " error message: " << e.what() << std::endl;
    }

    return 0;
}
