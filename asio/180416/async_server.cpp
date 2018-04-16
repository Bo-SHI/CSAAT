#include <boost/asio.hpp>
#include <boost/bind.hpp>

#include <iostream>

typedef boost::shared_ptr<boost::asio::ip::tcp::socket> socket_ptr;

void start_accept(socket_ptr sock);
void handle_accept(socket_ptr sock, const boost::system::error_code& err);

boost::asio::io_service service;
boost::asio::ip::tcp::endpoint ep(boost::asio::ip::tcp::v4(), 2002);
boost::asio::ip::tcp::acceptor acc(service, ep);

int main() {
    socket_ptr sock(new boost::asio::ip::tcp::socket(service));
    start_accept(sock);
    service.run();

    return 0;
}

void start_accept(socket_ptr sock) {
    acc.async_accept(*sock, boost::bind(handle_accept, sock, _1));
}

void handle_accept(socket_ptr sock, const boost::system::error_code& err) {
    if (err) return;
    //TODO
}
