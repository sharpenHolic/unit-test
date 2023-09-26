//
// Created by gqxiong on 9/22/23.
//
#include <gtest/gtest.h>
#include <deque>

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
};  // namespace STLTest