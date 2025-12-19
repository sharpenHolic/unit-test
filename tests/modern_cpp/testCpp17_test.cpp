//
// Created by gqxiong on 9/25/23.
//
#include <gtest/gtest.h>

namespace Cpp17BindingTest {
struct MyStruct {
    int n;
    std::string s;
};

TEST(BindingTest, Move1)
{
    MyStruct ms = {42, "jim"};
    auto&& [n, s] = std::move(ms);
    std::cout << "ms.s: " << ms.s << "\n";  // ms.s has value, because s point to, not move
    // after move
    std::string s1 = std::move(s);
    std::cout << "ms.s: " << ms.s << '\n';
    std::cout << "s: " << s << '\n';
    std::cout << "s1: " << s1 << '\n';

    EXPECT_EQ(ms.s, "");
    EXPECT_EQ(s, "");
    EXPECT_EQ(s1, "jim");
}

TEST(BindingTest, Move2)
{
    MyStruct ms = {42, "jim"};
    auto [n, s] = std::move(ms);

    std::cout << "ms.s: " << ms.s << '\n';  // empty, because ms has been moved to n and s
    std::cout << "s: " << s << '\n';

    EXPECT_EQ(ms.s, "");
    EXPECT_EQ(s, "jim");
}

// Note that to use structured bindings you need to follow certain rules when inheriting.
// All non-static data members must be defined in the same class (
// i.e. that is, all of these members either come directly from
// the final class or all come from the same parent class)
TEST(BindingTest, MapInsert)
{
    // use this way to insert a value to map
    std::map<std::string, int> coll;
    // add a declaration in a if ()
    if (auto [pos, ok] = coll.insert({"new", 42}); ok) {
        std::cout << "insert success: " << pos->first << ", " << pos->second << std::endl;
    }
}

std::tuple<char, float, std::string> getTuple1() { return {'a', 1.002, "hello"}; }
std::tuple<char, float, std::string> getTuple2() { return {'x', 100.002, "world"}; }
TEST(BindingTest, Tie)
{
    auto [a, b, c] = getTuple1();
    std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
    std::tie(a, b, c) = getTuple2();
    std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
}
};  // namespace Cpp17BindingTest