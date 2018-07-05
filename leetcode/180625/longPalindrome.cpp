#include <iostream>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int begin = 0;
        int end = 0;
        int size = (int)s.size();
        for (int i = 0; i < size; ++i) {
            std::string subStr;
            subStr.append(s.at(i));
            for (int j = i + 1; j < size; ++j) {
                std::string tmp(subStr);
                tmp.append(s.at(j));
                // TODO
            }
        }
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
    std::cout << s << " longest palindromis string is: " << obj.longestPalindrome(s) << std::endl;

    return 0;
}
