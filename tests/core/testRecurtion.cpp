//
// Created by gqxiong on 2023/10/19.
//
#include <iostream>
#include "gtest/gtest.h"

TEST(Re, Recurtion)
{
    std::function<int(int)> func = [&func](int n) {
        if (n == 1) {
            return n;
        }
        return n + func(n-1);
    };
    std::cout << func(3) << std::endl;
    std::cout << func(4) << std::endl;
    std::cout << func(5) << std::endl;
}