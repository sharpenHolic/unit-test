//
// Created by gqxiong on 2025/1/6.
//

#include "gtest/gtest.h"

class Base {
public:
    Base() {
        std::cout << "Base constructor" << std::endl;
    }
    virtual ~Base() {
        std::cout << "Base _m: " << _m << std::endl;
        assert(_m!=nullptr);
        delete _m;
        std::cout << "Base destructor" << std::endl;
    }

    int* _m{nullptr};
};

class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived constructor" << std::endl;
    }
    ~Derived() {
        std::cout << "Derived _m: " << _m << std::endl;
        assert(_m!=nullptr);
        delete _m;
        std::cout << "Derived destructor" << std::endl;
    }

    int* _m{nullptr};
};

void func(Base* basePtr) {
    delete basePtr;
}

TEST(class, test1)
{
    Derived* dPtr = new Derived();
    dPtr->_m = new int(10);
    func(dPtr);
}

TEST(class, test2)
{
    Base* dPtr = new Derived();
    dPtr->_m = new int(10);
    func(dPtr);
}

