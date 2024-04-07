//
// Created by gqxiong on 2023/11/2.
//
#include "gtest/gtest.h"

template <typename T>
void hashCombine(std::size_t& seed, const T& val) {
seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
template <typename... Types>
std::size_t combinedHashValue(const Types&... args) {
    std::size_t seed = 22331;            // 初 始 化seed
    (..., hashCombine(seed, args));  // 链 式 调 用hashCombine()

    std::cout << "seed: " << seed << std::endl;
    return seed;
}

// 调用
using Customer = std::pair<std::string*, std::string*>;

struct CustomerHash
{
    std::size_t operator() (const Customer& c) const {
        return combinedHashValue(c.first, c.second);
    }
};

TEST(HASH, CombineHash)
{
    std::unordered_map <Customer, std::string, CustomerHash > myMap;
    std::string s1{"hello"};
    std::string s2{"world"};
    myMap.insert({{&s1, &s2}, "test1"});
    myMap.insert({{&s1, &s2}, "test1"});
    myMap.insert({{&s2, &s1}, "test1"});

    std::cout << myMap.size() << std::endl;
}

