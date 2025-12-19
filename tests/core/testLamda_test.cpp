//
// Created by gqxiong on 2025/1/10.
//
#include "gtest/gtest.h"

int global = 10;

TEST(lamda, test1)
{
    std::cout << global << std::endl;
    auto foo = [=] () { ++global; };
    foo();
    std::cout << global << std::endl;
}

TEST(lamda, test2)
{
    int x = 1, y = 1;
    std::cout << x << " " << y << std::endl;
    auto foo = [x, y]() mutable { ++x; ++y; };
    foo();
    std::cout << x << " " << y << std::endl;
}