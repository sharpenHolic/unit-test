//
// Created by gqxiong on 2024/4/7.
//
#include "gtest/gtest.h"

TEST(case, test1)
{
    enum Type { A, B, C, D, O };

    for (auto in : {0, 1, 2, 3, 4}) {
        switch (in) {
        case Type::A:
        case Type::B:
        case Type::C:
            std::cout << "ABC" << std::endl;
            break;
        case Type::D:
        case Type::O:
            std::cout << "DO" << std::endl;
        default:
            break;
        }
    }
}