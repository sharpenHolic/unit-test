//
// Created by gqxiong on 2023/9/27.
//
#include <gtest/gtest.h>
#include <utility>
/*
Factory：工厂角色
        工厂角色负责实现创建所有实例的内部逻辑
Product：抽象产品角色
        抽象产品角色是所创建的所有对象的父类，负责描述所有实例所共有的公共接口
ConcreteProduct：具体产品角色
        具体产品角色是创建目标，所有创建的对象都充当这个角色的某个具体类的实例
*/
// 简单工厂模式
class Product {
   public:
    Product() = default;
    virtual ~Product() = default;
    virtual int Type() = 0;
};

class ConcreteProduct1 : public Product {
   public:
    ConcreteProduct1() = default;
    ~ConcreteProduct1() override = default;

    int Type() override { return 1; }
};

class ConcreteProduct2 : public Product {
   public:
    ConcreteProduct2() = default;
    ~ConcreteProduct2() override = default;
    int Type() override { return 2; }
};

class Factory {
   public:
    Factory() = default;
    ~Factory() = default;

    static Product* Create(int type);
};

Product* Factory::Create(int type)
{
    switch (type) {
    case 1:
        return new ConcreteProduct1();
    case 2:
        return new ConcreteProduct2();
    default:
        break;
    }
    return nullptr;
}

TEST(SimpleFactory, test1)
{
    Factory sf;
    auto p1 = sf.Create(1);
    auto p2 = sf.Create(2);

    EXPECT_EQ(p1->Type(), 1);
    EXPECT_EQ(p2->Type(), 2);
}