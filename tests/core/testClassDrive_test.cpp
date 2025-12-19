//
// Created by gqxiong on 2023/11/3.
//

#include "gtest/gtest.h"
#include <memory>

class Base {
public:
    int a;
};

class Derived : public Base{
public:
    int d_a;
    int d_b;
};

TEST(T, T){
    std::shared_ptr<Base> basePtr = std::make_shared<Derived>();
    auto fun = [](std::shared_ptr<Base>& bb) {
        std::shared_ptr<Derived> derivedPtr = std::static_pointer_cast<Derived>(bb);
    };

    fun(basePtr);
}

