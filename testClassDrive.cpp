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
//    std::shared_ptr<std::vector<std::shared_ptr<Base>>> BVec;
//    BVec = std::make_shared<std::vector<std::shared_ptr<Base>>>();
//    auto d1 = std::make_shared<Derived>();
//    auto d2 = std::make_shared<Derived>();
//    auto d3 = std::make_shared<Derived>();
//    BVec->emplace_back(d1);
//    BVec->emplace_back(d2);
//    BVec->emplace_back(d3);
//
//    for (int i = 0; i < BVec->size(); ++i) {
//        auto item = BVec->at(i);
//        auto itemD = std::dynamic_pointer_cast<Derived>(item);
//    }

    std::shared_ptr<Base> basePtr = std::make_shared<Derived>();
    auto fun = [](std::shared_ptr<Base>& bb) {
        std::shared_ptr<Derived> derivedPtr = std::static_pointer_cast<Derived>(bb);
    };

    fun(basePtr);

}

