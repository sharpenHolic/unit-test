//
// Created by gqxiong on 2024/3/18.
//
#include "gtest/gtest.h"

class A {
   public:
    A() = default;
    A(int) { std::cout << "A(int)" << std::endl; };
    A(int, int) { std::cout << "A(int, int)" << std::endl; }
};

class B {
   public:
    B() = default;
    explicit B(int) { std::cout << "B(int)" << std::endl; };
    explicit B(int, int) { std::cout << "B(int, int)" << std::endl; }
};

void BarA(A) {}

void BarB(B) {}
TEST(Explicit, test1)
{
    A a = 1;
    A aa = {1, 1};
    A aaa(1);

    // B b = 2;         error
    // B bb = {2, 2};   error
    B b(2);
    B bb(2, 2);

    std::cout << "----------- bar ---------" << std::endl;
    BarB(B(2, 3));
    //    BarB(2);   error
    std::cout << "----------- bar ---------" << std::endl;
    BarA(aa);
    std::cout << "----------- bar ---------" << std::endl;
    BarA(A(1));
    BarA(A(1, 2));
    BarA(1);
}
