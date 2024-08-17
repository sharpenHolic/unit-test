//
// Created by gqxiong on 9/22/23.
//
#include <gtest/gtest.h>
#include <deque>
#include <queue>
#include <boost/format.hpp>

namespace STLTest {
const int numElements = 1000000;
TEST(VectorPerformanceTest, InsertAndAccess)
{
    std::vector<int> myVector;
    std::cout << "vector Element Size: " << numElements << std::endl;

    auto startTime = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i) {
        myVector.push_back(i);
    }
    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> insertTime = endTime - startTime;
    std::cout << "Insertion time: " << insertTime.count() << " seconds" << std::endl;

    startTime = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i) {
        int value = myVector[i];
        value += 1;
    }
    endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> accessTime = endTime - startTime;
    std::cout << "Access time: " << accessTime.count() << " seconds" << std::endl;
    EXPECT_TRUE(insertTime.count() < 1.0);
    EXPECT_TRUE(accessTime.count() < 1.0);
}

TEST(DequePerformanceTest, InsertAndAccess)
{
    std::deque<int> myDeque;
    std::cout << "deque Element Size: " << numElements << std::endl;
    auto startTime = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i) {
        myDeque.push_back(i);
    }
    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> insertTime = endTime - startTime;
    std::cout << "Insertion time: " << insertTime.count() << " seconds" << std::endl;

    startTime = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i) {
        int value = myDeque[i];
        value += 1;
    }
    endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> accessTime = endTime - startTime;
    std::cout << "Access time: " << accessTime.count() << " seconds" << std::endl;
    EXPECT_TRUE(insertTime.count() < 1.0);
    EXPECT_TRUE(accessTime.count() < 1.0);
}

TEST(MemoryCostTest, Common)
{
    std::cout << boost::format("char: %1% bytes\n") % sizeof(char);
    std::cout << boost::format("short: %1% bytes\n") % sizeof(short);
    std::cout << boost::format("unsigned short: %1% bytes\n") % sizeof(unsigned short);
    std::cout << boost::format("int: %1% bytes\n") % sizeof(int);
    std::cout << boost::format("unsigned int: %1% bytes\n") % sizeof(unsigned int);
    std::cout << boost::format("long: %1% bytes\n") % sizeof(long);
    std::cout << boost::format("unsigned long: %1% bytes\n") % sizeof(unsigned long);
    std::cout << boost::format("float: %1% bytes\n") % sizeof(float);
    std::cout << boost::format("double: %1% bytes\n") % sizeof(double);
    std::cout << boost::format("uint8_t: %1% bytes\n") % sizeof(uint8_t);
}

TEST(MemoryCostTest, STL)
{
    std::cout << boost::format("vector<int>: %1% bytes\n") % sizeof(std::vector<int>);
    std::cout << boost::format("set<int>: %1% bytes\n") % sizeof(std::set<int>);
    std::cout << boost::format("queue<int>: %1% bytes\n") % sizeof(std::queue<int>);
    std::cout << boost::format("deque<int>: %1% bytes\n") % sizeof(std::deque<int>);
    std::cout << boost::format("map<int, int>: %1% bytes\n") % sizeof(std::map<int, int>);
    std::cout << boost::format("unodered_map<int, int>: %1% bytes\n") % sizeof(std::unordered_map<int, int>);
    std::cout << boost::format("multimap<int, int>: %1% bytes\n") % sizeof(std::multimap<int, int>);
    std::cout << boost::format("unodered_map<int, int>: %1% bytes\n") % sizeof(std::unordered_multimap<int, int>);
    std::cout << boost::format("array<int, 1>: %1% bytes\n") % sizeof(std::array<int, 1>);
    std::cout << boost::format("array<long, 2>: %1% bytes\n") % sizeof(std::array<long, 2>);

    std::vector<int> myV{1, 2, 3, 4, 5, 6, 7};
    std::cout << boost::format("vector<int> myV: %1% bytes + sizeof(int)(%2% bytes) * element num(%3%) = %4% bytes\n") %
                   sizeof(myV) % sizeof(int) % myV.size() % (sizeof(myV) + sizeof(int) * myV.size());
}

TEST(MemoryCostTest, Class)
{
    class A {};
    class B {
        int b;
    };
    class C : public B {};
    class D : public B {
        int d;
    };
    std::cout << boost::format("class A: %1% bytes\n") % sizeof(A);
    std::cout << boost::format("class B: %1% bytes\n") % sizeof(B);
    std::cout << boost::format("class C: %1% bytes\n") % sizeof(C);
    std::cout << boost::format("class D: %1% bytes\n") % sizeof(D);
}

TEST(MemoryCostTest, Class2)
{
    class Base {
       public:
        virtual void foo() = 0;
        virtual void boo() = 0;
    };  // 8 bytes

    class Derived1 : public Base {
       public:
        void foo() override {}
        void boo() override {}

       private:
        short _m0{};
    };  // 16 bytes

    class Derived2 : public Base {
       public:
        void foo() final {}
        void boo() final {}

       private:
        int _m0{0};
        int _m1{0};
    };  // 16 bytes

    std::cout << boost::format("class Base: %1% bytes\n") % sizeof(Base);
    std::cout << boost::format("class Derived1: %1% bytes\n") % sizeof(Derived1);
    std::cout << boost::format("class Derived2: %1% bytes\n") % sizeof(Derived2);
}

TEST(MemoryCostTest, Class3)
{
    class A {
        uint8_t b = 0;
        uint8_t b1 = 0;
    };

    std::cout << boost::format("class A: %1% bytes\n") % sizeof(A);
}

TEST(Multimap, test1)
{
    std::unordered_multimap<int, std::string> mm;
    mm.insert({1, "hello"});
    mm.insert({1, "hello2"});
    for (const auto& it : mm) {
        std::cout << it.second << std::endl;
    }
}

TEST(MultiMap, test2)
{
    std::unordered_multimap<int, std::string> myMap = {
      {1, "Apple"}, {2, "Banana"}, {1, "Apple2"}, {4, "Orange"}, {1, "Apple3"}};

    int key = 1;
    std::string valueToDelete = "Apple3";

    auto range = myMap.equal_range(key);
    for (auto it = range.first; it != range.second;) {
        if (it->second == valueToDelete) {
            it = myMap.erase(it);
            //            break; // 可选，如果只想删除第一个匹配的值
        } else {
            ++it;
        }
    }

    // 打印剩余的键值对
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

TEST(STRINGTOINT, test1)
{
    std::string ss = "a0091a11";
    int ii = atoi(ss.c_str());
    std::cout << "ii: " << ii << std::endl;
}

TEST(STRING, test2)
{
    // 查找string中的字串
    std::string ss = "a0091a11";
    if (ss.find("a") != std::string::npos) {
        std::cout << "ss: " << ss << std::endl;
    }
}

TEST(VectorSize, test1)
{
    std::vector<int*> v1{nullptr};
    std::cout << "v1 size: " << v1.size() << std::endl;

    std::vector<int*> v2;
    std::cout << "v2 size: " << v2.size() << std::endl;

    int* iPtr{nullptr};
}

};  // namespace STLTest
