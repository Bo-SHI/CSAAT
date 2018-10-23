#include <iostream>
#include <algorithm>
#include <vector>

void print(const std::vector<int>& v) {
    std::cout << "Begin:\n";
    for (auto& e : v) {
        std::cout << e << "\t";
    }
    std::cout << std::endl;
    std::cout << "End!\n";
}

int main() {
    std::vector<int> v1 {5,2,3,4};
    print(v1);

    std::vector<int> v2;
    std::set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(v2));

    print(v2);
    return 0;
}
