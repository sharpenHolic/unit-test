//
// Created by gqxiong on 2024/1/4.
//

// 每个clock有自己的名字和唯一的id，不同clock可以有相同的id。具备相同id的clock之间没有crossing
// 不同的接口带有很多clock，需要一个函数判断接口之间是否有crossing


#include "gtest/gtest.h"

class Clock {
   public:
    Clock(std::string&& name, int id)
    {
        _name = std::move(name);
        _id = id;
    };

    std::string _name{""};
    int _id{-1};
};

bool isCrossing(const std::vector<Clock*>& v1, const std::vector<Clock*>& v2)
{
    std::set<int> ids1{};
    std::set<int> ids2{};

    for (const auto& clk1 : v1) {
        ids1.insert(clk1->_id);
    }

    for (const auto& clk2 : v2) {
        ids2.insert(clk2->_id);
    }

    if (ids1.size() == ids2.size()) {
        for (auto& id1 : ids1) {
            erase_if(ids2, [&](const auto& id) -> bool { return id1 == id; });
        }
    } else {
        return true;
    }

    return !ids2.empty();
}

TEST(NoCrossing, test0)
{
    Clock clk1("clk1", 1);
    Clock clk2("clk2", 2);
    Clock clk3("clk3", 3);

    // no crossing
    std::vector<Clock*> v1{&clk1, &clk2, &clk3};
    std::vector<Clock*> v2{&clk1, &clk2, &clk3};

    std::cout << "isCrossing: " << isCrossing(v1, v2) << std::endl;
    ASSERT_EQ(isCrossing(v1, v2), false);
}

TEST(NoCrossing, test1)
{
    Clock clk1("clk1", 1);
    Clock clk2("clk2", 1);
    Clock clk3("clk3", 3);
    Clock clk4("clk4", 3);

    // no crossing
    std::vector<Clock*> v1{&clk1, &clk3};
    std::vector<Clock*> v2{&clk2, &clk3};
    std::vector<Clock*> v3{&clk2, &clk4};

    std::cout << "isCrossing: " << isCrossing(v1, v2) << std::endl;
    ASSERT_EQ(isCrossing(v1, v2), false);

    std::cout << "isCrossing: " << isCrossing(v1, v3) << std::endl;
    ASSERT_EQ(isCrossing(v1, v3), false);
}

TEST(NoCrossing, test2)
{
    Clock clk1("clk1", 1);
    Clock clk2("clk2", 1);
    Clock clk3("clk3", 3);

    // no crossing
    std::vector<Clock*> v1{&clk1, &clk2, &clk3};
    std::vector<Clock*> v2{&clk1, &clk3};
    std::vector<Clock*> v3{&clk2, &clk3};

    std::cout << "isCrossing: " << isCrossing(v1, v2) << std::endl;
    std::cout << "isCrossing: " << isCrossing(v2, v3) << std::endl;
    ASSERT_EQ(isCrossing(v1, v2), false);
    ASSERT_EQ(isCrossing(v2, v3), false);
}

TEST(Crossing, test0)
{
    Clock clk1("clk1", 1);
    Clock clk2("clk2", 2);
    Clock clk3("clk3", 3);

    // no crossing
    std::vector<Clock*> v1{&clk1, &clk2, &clk3};
    std::vector<Clock*> v2{&clk1, &clk3};
    std::vector<Clock*> v3{&clk2, &clk3};

    std::cout << "isCrossing: " << isCrossing(v1, v2) << std::endl;
    std::cout << "isCrossing: " << isCrossing(v2, v3) << std::endl;
    ASSERT_EQ(isCrossing(v1, v2), true);
    ASSERT_EQ(isCrossing(v2, v3), true);
}
