#include <boost/asio.hpp>

#include <iostream>

int main(int argc, char *argv[]) {
    boost::asio::io_service service;
    boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address::from_string("127.0.0.1"), 2001);
    boost::asio::ip::tcp::socket sock(service);
    sock.connect(ep);

    return 0;
}
