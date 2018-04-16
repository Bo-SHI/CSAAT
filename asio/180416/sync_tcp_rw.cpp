#include <boost/asio.hpp>

#include <iostream>

using namespace boost::asio;

int main(int argc, char *argv[]) {
    io_service service;
    ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 2001);
    ip::tcp::socket sock(service);
    try {
        sock.connect(ep);
        sock.write_some(buffer("GET /index.xml\r\n"));
        std::cout << "bytes available " << sock.available() << std::endl;
        char buff[512];
        size_t read = sock.read_some(buffer(buff));
        std::cout << "bytes read " << read << std::endl;
    } catch (boost::system::system_error e) {
        std::cout << "error code: " << e.code() << " error message: " << e.what() << std::endl;
    }

    return 0;
}

