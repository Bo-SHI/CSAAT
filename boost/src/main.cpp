#include <iostream>
#include <map>

#include <boost/shared_ptr.hpp>

struct Battle {
    typedef boost::shared_ptr<Battle> ptr;

    int battleId;
};

int main(int argc, char *argv[]) {
    Battle::ptr battle (new Battle);
    battle->battleId = 1;

    std::map<int, Battle::ptr> mBattles;
    mBattles.insert(std::make_pair(1, battle));

    auto it = mBattles.find(1);
    if (it == mBattles.end()) {
        std::cout << "find error\n";
        return 0;
    }

    Battle::ptr nBattle;
    nBattle.swap(it->second);

    if (it->second) {
        std::cout << "exist\n";
    } else {
        std::cout << "nonexist\n";
    }

    return 0;
}
