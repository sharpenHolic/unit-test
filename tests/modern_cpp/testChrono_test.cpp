//
// Created by gqxiong on 2024/11/29.
//
#include "gtest/gtest.h"
#include <bits/stdc++.h>
#include <compare>
#include <chrono>
using namespace std;
using namespace std::chrono;

TEST(compare, Test1)
{
    int a = 91, b = 110;
    auto ans1 = a <=> b;

    if (ans1 < 0) {
        cout << "a < b\n";
    } else if (ans1 == 0) {
        cout << "a == b\n";
    } else if (ans1 > 0) {
        cout << "a > b\n";
    }

    vector<int> v1{10, 2, 9, 10};
    vector<int> v2{3, 6, 9};
    auto ans2 = v1 <=> v2;

    if (ans2 < 0) {
        cout << "v1 < v2\n";
    } else if (ans2 == 0) {
        cout << "v1 == v2\n";
    } else if (ans2 > 0) {
        cout << "v1 > v2\n";
    }

    cout << endl;
}

//TEST(chrono, Test1) {
//    auto date1 = 2020y/sep/8;
//    auto date2 = 21d/oct/2018;
//    auto date3 = jan/27/2019;
//}
