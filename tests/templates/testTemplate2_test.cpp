//
// Created by gqxiong on 2024/1/2.
//
#include "gtest/gtest.h"

template <typename T>
void myFunc(std::vector<T> funcs)
{
    for (const auto& f : funcs) {
        f();
    }
}

TEST(FUNC, test1) {
    auto func1 = [](){std::cout << "hello" << std::endl;};
    auto func2 = [](){std::cout << "hello2" << std::endl;};
    auto func3 = [](){std::cout << "hello3" << std::endl;};
    std::vector<std::function<void()>> v{func1, func2, func3};
    myFunc(v);
}