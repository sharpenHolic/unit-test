//
// Created by gqxiong on 2024/12/3.
//
// https://harttle.land/2015/07/21/effective-cpp-3.html
#include "gtest/gtest.h"
#include <iostream>

TEST(const, test1)
{
    char greeting[] = "Hello";
    char *p1 = greeting;              // non-const pointer, non-const data
    const char *p2 = greeting;        // non-const pointer, const data
    char *const p3 = greeting;        // const pointer, non-const data
    const char *const p4 = greeting;  // const pointer, const data
}

// STL的iterator也是类似的，如果你希望指针本身是常量，可以声明 const iterator； 如果你希望指针指向的对象是常量，请使用
// const_iterator
TEST(const, test2)
{
    std::vector<int> vec;

    // iter acts like a T* const
    const std::vector<int>::iterator iter = vec.begin();
    *iter = 10;  // OK, changes what iter points to
    //    ++iter;      // error! iter is const

    // cIter acts like a const T*
    std::vector<int>::const_iterator cIter = vec.begin();
    //    *cIter = 10;  // error! *cIter is const
    ++cIter;  // fine, changes cIter
}

// 声明常量成员函数是为了确定哪些方法可以通过常量对象来访问，另外一方面让接口更加易懂：
// 很容易知道哪些方法会改变对象，哪些不会 成员方法添加常量限定符属于函数重载。常量对象只能调用常量方法，
// 非常量对象优先调用非常量方法，如不存在会调用同名常量方法。 常量成员函数也可以在类声明外定义，但声明和定义都需要指定
// const 关键字
class TextBlock {
   public:
    TextBlock(std::string s) : text(s) {}
    const char &operator[](std::size_t position) const  // operator[] for
    {
        return text[position];
    }  // const objects

    char &operator[](std::size_t position)  // operator[] for
    {
        return const_cast<char&>(static_cast<const TextBlock&>(*this)[position]);
    }  // non-const objects

   private:
    std::string text;
};
TEST(const, test3)
{
    TextBlock tb("Hello");
    const TextBlock ctb("World");
    tb[0] = 'x';  // fine — writing a non-const TextBlock
    //    ctb[0] = 'x';            // error! — writing a const TextBlock
}



// 使用 mutable 改变常量方法中的成员
class CTextBlock {
public:
    std::size_t length() const;

private:
    char *pText;

    mutable std::size_t textLength;         // these data members may
    mutable bool lengthIsValid;             // always be modified
};

std::size_t CTextBlock::length() const{
    if (!lengthIsValid) {
        textLength = strlen(pText);
        lengthIsValid = true;
    }
    return textLength;
}