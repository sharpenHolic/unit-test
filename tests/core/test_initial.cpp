//
// Created by gqxiong on 2024/12/3.
//
#include "gtest/gtest.h"

class A {
};

class B {
    B() : a(), _m() {}  // 使用这种方式初始化
    B(int) {
        a = A();  // 赋值, 不要使用这种方式初始化
    }
    int _m;
    A a;
};