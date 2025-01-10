//
// Created by gqxiong on 2024/11/7.
//

#include "gtest/gtest.h"

struct S {
    int i;
    int j;
    float f;

    void print()
    {
        std::cout << "i: " << i << std::endl;
        std::cout << "j: " << j << std::endl;
        std::cout << "f: " << f << std::endl;
    }

    constexpr auto operator<=>(const S& s) const = default;
};

bool compare(S& lhs, S& rhs) { return lhs < rhs; }

void initFunc()
{
    S s1{.i = 3, .j = 3, .f = 3.14f};
    s1.print();

    S s2{.i = 3, .j = 2, .f = 3.2121f};
    s2.print();

    std::cout << "compare: " << compare(s1, s2) << std::endl;
}

TEST(CPP20, 1) { initFunc(); }

#include <source_location>
#include <format>
std::string make_log(int id, std::string_view description) { return std::format("Event {}: {}", id, description); }

void do_log()
{
    std::cout << make_log(std::source_location::current().line(), std::source_location::current().function_name())
              << std::endl;
}

TEST(CPP20, 2) { do_log(); }