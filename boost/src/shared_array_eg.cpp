#include <iostream>
#include <boost/shared_array.hpp>

int main(int argc, char *argv[]) {
    char *p = new char[4096];
    boost::shared_array<char> sa(p);

    sa[0] = '0';
    std::cout << sa[0] << std::endl;

    return 0;
}
