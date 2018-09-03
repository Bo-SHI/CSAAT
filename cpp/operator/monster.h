#ifndef __NOTE_MONSTER_H__
#define __NOTE_MONSTER_H__

#include <string>

namespace Note {

struct MonsterArg {

};

struct MonsterGroup {
    std::string desc;

    std::string operator ()() {
        return desc;
    }
};

class B {
public:
    virtual MonsterGroup func(const MonsterArg& arg) {
        return MonsterGroup {
            "B class"
        };
    }

    MonsterGroup operator() (const MonsterArg& arg) {
        return this->func(arg);
    }
};

class D : public B {
public:
    virtual MonsterGroup func(const MonsterArg& arg) {
        return MonsterGroup{
            "D class"
        };
    }
};

}// namespace Note

#endif // __NOTE_MONSTRE_H__
