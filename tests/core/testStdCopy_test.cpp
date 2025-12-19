//
// Created by Administrator on 2024/1/6.
//
#include "gtest/gtest.h"

// 学习 std::copy
TEST(STDCOPY, test1)
{
    int a[5] = {1, 2, 3, 4, 5};
    int b[5];
    std::vector<int> v;

    std::copy(a, a + 5, b);
    std::copy(a, a + 5, back_inserter(v));

    std::cout<< "原始a数组为: ";
    std::copy(a, a + 5, std::ostream_iterator<int>(std::cout, " "));
    std::cout<< "\nb数组为: ";
    std::copy(b, b + 5, std::ostream_iterator<int>(std::cout, " "));
    std::cout<< "\nvector向量为: ";
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
}

