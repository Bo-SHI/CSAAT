#include <iostream>
#include <random>
#include <exception>
#include <string>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: ./a.out Seed(int)" << std::endl;
        return 0;
    }
    int seed = 0;
    try {
        std::string seedStr = argv[1];
        seed = std::stoi(seedStr);

        std::cout << "seed is: " << seed << "\n";
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return 0;
    }

    std::vector<int> pools{1,2,3,4,5,6,7,8,9,11,13,14,32,43};
    std::default_random_engine engine(seed);
    std::uniform_int_distribution<> dis(0, std::max(0, (int)pools.size()-1));
    for (int i = 0; i < 10; ++i) {
        int index = dis(engine);
        std::cout << "index:" << index << std::endl;
        std::cout << "value:" << pools.at(index) << std::endl;
    }

    return 0;
}
