//
// Created by gqxiong on 2024/1/4.
//

#include "gtest/gtest.h"

TEST(Erase_if, test1)
{
    std::vector<int> v1{1, 2, 3, 4, 5};

    for (auto i : {1, 2, 3}) {
        erase_if(v1, [&](const auto& num) {
            return i == num;
        });
    }

    for (auto i : v1) {
        std::cout << "i: " << i << std::endl;
    }
}