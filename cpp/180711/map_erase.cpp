#include <iostream>
#include <map>

int main(int argc, char *argv[]) {
    std::map<int, int> m;
    m.insert(std::make_pair(1, 1));
    m.insert(std::make_pair(2, 2));
    m.insert(std::make_pair(3, 3));
    m.insert(std::make_pair(4, 4));

    auto begin = m.begin();
    auto end = m.end();
    auto  it = m.erase(begin, end);
    std::cout << "it: " << it->second << std::endl;

    return 0;
}
