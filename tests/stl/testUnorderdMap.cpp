//
// Created by gqxiong on 2024/1/5.
//

#include "gtest/gtest.h"

TEST(UnoderedMap, remove)
{
    std::unordered_map<int, int> um;
    um.insert({1, 11});
    um.insert({2, 22});
    um.insert({3, 33});
    um.insert({4, 44});
    um.insert({5, 55});

    auto find = um.equal_range(2);
    erase_if(um,[&](auto p){ return p.first == 1;});

    for (const auto &item : um) {
        std::cout << item.second << std::endl;
    }
}


struct hashPair {
    template <class T1, class T2>
    size_t operator()(const std::pair<T1, T2>& p) const
    {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
TEST(UnoderedMap, remove1)
{
    std::unordered_map<std::pair<int, int>, int, hashPair> um;
    um.insert({{1,1}, 11});
    um.insert({{2,2}, 22});

    erase_if(um,[&](auto p){ return p.first.first == 1;});

    for (auto item : um) {
        std::cout << item.second << std::endl;
    }
}
