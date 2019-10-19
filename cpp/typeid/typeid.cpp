#include <iostream>
#include <typeinfo>

class Base {
public:
    virtual void f();
};

class Derived : public Base {};

int main(int argc, char *argv[]) {
    std::cout << typeid(int).name() << std::endl;
    std::cout << typeid(unsigned).name() << std::endl;

    std::cout << typeid(Base).name() << std::endl;
    std::cout << typeid(Derived).name() << std::endl;

    //Base b;
    //Derived d;
    //std::cout << typeid(b).name() << std::endl;
    //std::cout << typeid(d).name() << std::endl;

    //Base* pb (new Base);
    //std::cout << typeid(pb).name() << std::endl;
    //std::cout << typeid(*pb).name() << std::endl;

    //Base* pb1 (new Derived);
    //std::cout << typeid(pb1).name() << std::endl;
    //std::cout << typeid(*pb1).name() << std::endl;

    return 0;
}
