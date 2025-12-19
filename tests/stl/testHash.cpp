//
// Created by gqxiong on 2023/11/2.
//
#include "gtest/gtest.h"
#include <unordered_set>
#include <functional>

template <typename T>
void hashCombine(std::size_t& seed, const T& val)
{
    seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
template <typename... Types>
std::size_t combinedHashValue(const Types&... args)
{
    std::size_t seed = 22331;        // 初 始 化seed
    (..., hashCombine(seed, args));  // 链 式 调 用hashCombine()

    std::cout << "seed: " << seed << std::endl;
    return seed;
}

// 调用
using Customer = std::pair<std::string*, std::string*>;

struct CustomerHash {
    std::size_t operator()(const Customer& c) const { return combinedHashValue(c.first, c.second); }
};

TEST(HASH, CombineHash)
{
    std::unordered_map<Customer, std::string, CustomerHash> myMap;
    std::string s1{"hello"};
    std::string s2{"world"};
    myMap.insert({{&s1, &s2}, "test1"});
    myMap.insert({{&s1, &s2}, "test1"});
    myMap.insert({{&s2, &s1}, "test1"});

    std::cout << myMap.size() << std::endl;
}


struct TestData {
    int id;
    std::string name;

    bool operator==(const TestData& other) const {
        return id == other.id && name == other.name;
    }
};

struct TestDataHash {
    size_t operator()(const TestData& data) const {
        size_t idHash = std::hash<int>{}(data.id);
        size_t nameHash = std::hash<std::string>{}(data.name);
        return idHash ^ nameHash;  // 可以根据实际需求选择合适的哈希组合方式
    }
};
TEST(hash, test1)
{
    std::unordered_set<TestData, TestDataHash> hashSet;
    std::unordered_set<size_t> hashValues;  // 用于记录哈希值的集合

    for (int i = 0; i < 1000000000; ++i) {
        TestData data;
        data.id = i;
        data.name = "Test" + std::to_string(i);

        size_t hashValue = TestDataHash{}(data);  // 计算哈希值

        // 检查哈希碰撞
        if (hashValues.count(hashValue) > 0) {
            std::cout << "Hash collision detected for TestData with id " << i << std::endl;
        } else {
            hashSet.insert(data);
            hashValues.insert(hashValue);
        }
    }
}