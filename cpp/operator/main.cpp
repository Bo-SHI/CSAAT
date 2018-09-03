#include <iostream>

#include "monster.h"

int main(int argc, char *argv[]) {
    Note::B* obj = new Note::D();
    // Note::D obj;
    Note::MonsterArg arg;
    std::cout << (*obj)(arg)() << std::endl;
    delete obj;
    return 0;
}
