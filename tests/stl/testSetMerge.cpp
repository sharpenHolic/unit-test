//
// Created by gqxiong on 2024/1/9.
//

#include "gtest/gtest.h"
#include <set>
#include <algorithm>

TEST(SetMerge, test1)
{
    std::set<int> s1{1, 2, 3, 4};
    std::set<int> s2{5, 6, 7};

    s1.insert(s2.begin(), s2.end());

    for (auto i : s1) {
        std::cout << "i = " << i << std::endl;
    }
}

TEST(SetMerge, test2)
{
    std::set<int> set1 = {1, 2, 3};
    std::set<int> set2 = {3, 4, 5};

    std::set<int> newSet;
    std::merge(set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(newSet, newSet.begin()));

    // 打印新的集合
    for (const auto& element : newSet) {
        std::cout << element << " ";
    }
}