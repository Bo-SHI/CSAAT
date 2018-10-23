#include <iostream>
#include <functional>

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

class Printer {
    public:
        Printer(boost::asio::io_service& io) :
            timer_(io, boost::posix_time::seconds(1)),
            count_(0) {
                // 这里使用了 std::bind, 结果证明跟boost::bind 用法一样
                timer_.async_wait(std::bind(&Printer::print, this));
            }

        ~Printer() {
            std::cout << "Final count: " << count_ << std::endl;
        }

        void print() {
            if (count_ < 5) {
                std::cout << count_<< std::endl;
                ++count_;

                timer_.expires_at(timer_.expires_at() + boost::posix_time::seconds(1));
                timer_.async_wait(std::bind(&Printer::print, this));
            }
        }

    private:
        boost::asio::deadline_timer timer_;
        int count_;
};

int main() {
    boost::asio::io_service io;
    Printer p(io);
    io.run();

    return 0;
}
