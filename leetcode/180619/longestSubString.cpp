#include <iostream>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubString(std::string s) {
        int length = 0;
        int size = (int)s.size();
        std::unordered_map<char, int> um;
        for (int i = 0, j = 0; j < size; ++j) {
            char ch = s.at(j);
            auto it = um.find(ch);
            if (it != um.end()) {
                i = std::max(it->second, i);
            }

            length = std::max(length, j - i + 1);
            if (it == um.end()) {
                um.insert(std::make_pair(ch, j+1));
            } else {
                it->second = j + 1;
            }
        }

        return length;
    }
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: a.cout std::string\n";
        return 0;
    }

    char *tmpS = argv[1];
    std::string s = tmpS;

    Solution obj;
    std::cout << s << " longest sub string is: " << obj.lengthOfLongestSubString(s) << std::endl;

    return 0;
}
