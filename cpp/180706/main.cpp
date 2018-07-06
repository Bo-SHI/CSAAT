#include "unique.h"

#include <iostream>
#include <cstdlib>
#include <set>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: a.out digits\n";
        exit(0);
    }

    std::set<int> s;
    int num = std::atoi(argv[1]);
    for (int i = 0; i < num; ++i) {
        s.insert(Note::randDigits(8));
    }

    std::cout << "s size: " << s.size() << std::endl;
    exit(0);
}
