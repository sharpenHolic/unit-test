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

};  // namespace MoveTest
