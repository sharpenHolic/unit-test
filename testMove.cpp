//
// Created by gqxiong on 2023/9/26.
//

#include <gtest/gtest.h>

namespace MoveTest {
class Widget {
   public:
    Widget() { std::cout << "default construct" << std::endl; }
    //    explicit Widget(std::string s) : _s(std::move(s)) { std::cout << "move construct: " << _s << std::endl; }
    //    explicit Widget(std::string s) : _s(s) { std::cout << "& construct: " << _s << std::endl; }
    explicit Widget(std::string&& s) : _s(s) { std::cout << "&& construct: " << _s << std::endl; }

    ~Widget() { std::cout << "default destruct" << std::endl; }
    Widget(Widget& org)
    {
        this->_s = org._s;
        std::cout << "copy construct" << std::endl;
    }

   private:
    std::string _s;
};

TEST(MoveTest, test1)
{
    //    Widget w;
    Widget w2("hello");
    Widget w3(std::move(std::string("world")));
    //    Widget w4{w3};
}

void func(std::vector<int>&& vvv)
{
    std::vector<int> res = std::move(vvv);
    for (auto i : res) {
        std::cout << i;
    }
}

TEST(MoveTest, testVector)
{
    std::vector<int> vii{1, 2, 3, 4, 5, 6, 7};

    func(std::move(vii));
    func(std::vector<int>({1, 2, 3, 4, 5, 6, 7}));
    func(std::move(vii));
    //    Widget w4{w3};
}

void func2(std::vector<int>&& vvv)
{
    std::unordered_map<int, std::vector<int>> mm;
    mm.insert({1, vvv});
    for (auto i : mm) {
        for (auto ii : i.second) {
            std::cout << ii << std::endl;
        }
    }
}

TEST(MoveTest, testVector2)
{
    std::vector<int> vii{1, 2, 3, 4, 5, 6, 7};

    func2(std::move(vii));
    func2(std::vector<int>({1, 2, 3, 4, 5, 6, 7}));

    //    Widget w4{w3};
}

};  // namespace MoveTest
