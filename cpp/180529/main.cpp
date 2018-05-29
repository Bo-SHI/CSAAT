#include <iostream>

#include "hash_map.h"

int main() {
    Note::MyHashMap m;
    m.put(1,1);
    m.put(2,2);
    std::cout << m.get(1) << std::endl;
    std::cout << m.get(2) << std::endl;
    m.put(2,1);
    std::cout << m.get(2) << std::endl;
}
