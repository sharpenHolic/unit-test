//
// Created by gqxiong on 2023/10/19.
//

#include <gtest/gtest.h>

#define SWAP(a, b)          \
    do {                    \
        typeof(a) temp = a; \
        a = b;              \
        b = temp;           \
    } while (0)
std::vector<int> vec{2, 4, 0, 1, 23, 9, 5, 12, 15, 3, 100, 200, 23, 88};
static void PrintVec(const std::vector<int>& vec)
{
    for (const auto& v : vec) {
        std::cout << v << ", ";
    }
    std::cout << std::endl;
}

TEST(SORT, Data) { PrintVec(vec); }

TEST(SORT, Bubble)  // O(n^2)
{
    std::cout << "----test Bubble----\n";
    std::vector<int> res = vec;
    for (int i = 0; i < res.size() - 1; ++i) {
        for (int j = 0; j < res.size() - 1; ++j) {
            if (res[j] > res[j + 1]) {
                SWAP(res[j], res[j + 1]);
            }
        }
    }
    PrintVec(res);
}

TEST(SORT, Select)  // O(n^2)
{
    std::cout << "----test Select----\n";
    std::vector<int> res = vec;
    for (int i = 0; i < res.size(); ++i) {
        int min = i;
        for (int j = i + 1; j < res.size(); ++j) {
            if (res[j] < res[min]) {
                min = j;
            }
        }
        if (min != i) {
            SWAP(res[min], res[i]);
        }
    }
    PrintVec(res);
}

TEST(SORT, Insert)  // O(n^2)
{
    std::cout << "----test Insert----\n";
    std::vector<int> res = vec;
    for (int i = 1; i < res.size(); ++i) {
        int j = i - 1;
        auto key = res[i];
        while ((j >= 0) && (key < res[j])) {
            res[j + 1] = res[j];
            j--;
        }
        res[j + 1] = key;
    }
    PrintVec(res);
}
