#include <boost/asio.hpp>

#include <iostream>

using namespace boost::asio;

int main(int argc, char *argv[]) {
    io_service service;
    ip::tcp::resolver resolver(service);
    ip::tcp::resolver::query query("www.google.com", "80");
    ip::tcp::resolver::iterator iter = resolver.resolve(query);
    ip::tcp::endpoint ep = *iter;
    std::cout << ep.address().to_string() << ":" << ep.port() << std::endl;// << "/" << ep.protocol() << std::endl; I donot understand protocoltype no operator<<
    return 0;
}
