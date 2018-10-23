#include <iostream>
#include <ctime>

int main() {
    for (int i = 0; i < 3; ++i) {
        std::time_t now = std::time(nullptr);
        std::cout << std::asctime(std::localtime(&now)) << std::endl;
        std::cout << now << std::endl;
        std::cout << (now>>i) << std::endl;
    }

    return 0;
}
