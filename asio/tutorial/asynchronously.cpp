#include <iostream>

#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

void print(const boost::system::error_code& /*e*/) {
    std::cout << "hello world!\n";
}

int main() {
    boost::asio::io_service io;
    boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
    t.async_wait(&print);

    io.run();
    return 0;
}
