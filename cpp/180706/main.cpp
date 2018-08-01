#include "unique.h"

#include <iostream>
#include <cstdlib>
#include <set>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Usage: a.out count digits\n";
        exit(0);
    }

    std::set<int> s;
    int num = std::atoi(argv[1]);
    int digits = std::atoi(argv[2]);
    for (int i = 0; i < num; ++i) {
        int digit = Note::randDigits(digits);
        if (i < 10) {
            std::cout << "num " << i << ": " << digit << std::endl;
        }
        s.insert(digit);
    }

    std::cout << "s size: " << s.size() << std::endl;
    exit(0);
}
