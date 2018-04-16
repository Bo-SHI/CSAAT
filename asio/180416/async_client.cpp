#include <boost/asio.hpp>

#include <iostream>

void connect_handler(const boost::system::error_code& ec) {
    std::cout << "connect success!\n";
}

int main(int argc, char* argv[]) {
    boost::asio::io_service service;
    boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address::from_string("127.0.0.1"), 2002);
    boost::asio::ip::tcp::socket sock(service);
    sock.async_connect(ep, connect_handler);
    service.run();
    return 0;
}
