#include <iostream>
#include <functional>
#include <thread>

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/thread.hpp>

class Printer {
    public:
        Printer(boost::asio::io_service& io)
            : strand_(io)
              , timer1_(io, boost::posix_time::seconds(1))
              , timer2_(io, boost::posix_time::seconds(1))
              , count_(0)  {
                  timer1_.async_wait(strand_.wrap(boost::bind(&Printer::print1, this)));
                  timer2_.async_wait(strand_.wrap(boost::bind(&Printer::print2, this)));
              }

        ~Printer() {
            std::cout << "Final count: " << count_ << std::endl;
        }

        void print1() {
            if (count_ < 10) {
                std::cout << "timer1, " << count_ << std::endl;
                ++count_;
                timer1_.expires_at(timer1_.expires_at() + boost::posix_time::seconds(1));
                timer1_.async_wait(strand_.wrap(boost::bind(&Printer::print1, this)));
            }
        }

        void print2() {
            if (count_ < 10) {
                std::cout << "timer2, " << count_ << std::endl;
                ++count_;
                timer2_.expires_at(timer2_.expires_at() + boost::posix_time::seconds(1));
                timer2_.async_wait(strand_.wrap(boost::bind(&Printer::print2, this)));
            }
        }

    private:
        boost::asio::strand strand_;
        boost::asio::deadline_timer timer1_;
        boost::asio::deadline_timer timer2_;
        int count_;
};

int main() {
    boost::asio::io_service io;
    Printer p(io);
    // 这里使用boost::bind, 是因为run被重载了
    std::thread t(std::bind(static_cast<size_t (boost::asio::io_service::*)()>(&boost::asio::io_service::run), &io));
    // std::thread t(boost::bind(&boost::asio::io_service::run, &io));
    io.run();
    t.join();

    return 0;
}
