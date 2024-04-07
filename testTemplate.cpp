//
// Created by gqxiong on 9/22/23.
//
#include <gtest/gtest.h>

#include <utility>

namespace TPartialTest {
// partial template
template <class T, class U>
U print(T t)
{
    std::cout << "T t = " << t << std::endl;
    return static_cast<U>(t);
}

template <class U>
U print(int t)
{
    std::cout << "int t = " << t << std::endl;
    return static_cast<U>(t);
}
TEST(Template, Partial)
{
    print<int, double>(1.0);
    print<int>(2);
}
};  // namespace TPartialTest

namespace TLocalClassTest {

class Interface {
   public:
    virtual void Work() = 0;
};

template <class T, class P>
std::shared_ptr<Interface> MakeAdapter(const T &obj, const P &arg)
{
    class Local : public Interface {
       public:
        Local(const T &obj, P arg) : _obj(obj), _arg(std::move(arg)) {}
        void Work() override { _obj.Call(_arg); }

       private:
        T _obj;
        P _arg;
    };
    return std::make_shared<Local>(Local(obj, arg));
}

class WorkerIndian {
   public:
    static void Call(int i) { std::cout << "indian work on i: " << i << std::endl; }
};

class WorkerChina {
   public:
    static void Call(const std::string &s) { std::cout << "chinese work on s: " << s << std::endl; }
    static void Smoke() { std::cout << "do some smoke: " << std::endl; }
};

void WorkOnMyWay(std::vector<std::shared_ptr<Interface>> &workers)
{
    for (const auto &w : workers) {
        w->Work();
    }
}

TEST(Template, ClassLocal)
{
    std::vector<std::shared_ptr<Interface>> workFactory;
    workFactory.emplace_back(MakeAdapter(WorkerIndian(), 007));
    workFactory.emplace_back(MakeAdapter(WorkerChina(), std::string("996")));
    WorkOnMyWay(workFactory);
}
};  // namespace TLocalClassTest

namespace TStaticDispatchTest {
enum WAYS { TYPE1, TYPE2, TYPE3 };

template <int v>
struct Int2Type {
    enum { value = v };
};

class Base {
   public:
    Base() = default;
    virtual void Process() {}
    virtual void FPrint() { std::cout << "d = " << d << ", r = " << r << std::endl; }

   public:
    virtual int &GetD() final { return d; }
    virtual int &GetR() final { return r; }

   private:
    int d{0};
    int r{0};
};

// template <int type>
class FindDriver {
   public:
    static void process(const std::shared_ptr<Base>& obj) { obj->Process(); }
};

class Find1 : public Base {
   public:
    Find1() = default;
    void FPrint() override
    {
        Base::FPrint();
        std::cout << "this is TYPE1" << std::endl;
    }
    void Process() override
    {
        GetD() = 11;
        GetR() = 11;
    }
};

class Find2 : public Base {
   public:
    Find2() = default;
    void FPrint() override
    {
        Base::FPrint();
        std::cout << "this is TYPE2" << std::endl;
    }
    void Process() override
    {
        GetD() = 22;
        GetR() = 22;
    }
};

class Find3 : public Base {
   public:
    Find3() = default;
    void FPrint() override
    {
        Base::FPrint();
        std::cout << "this is TYPE3" << std::endl;
    }
    void Process() override
    {
        GetD() = 33;
        GetR() = 33;
    }
};

template <int type>
class findBuilder {
   private:
    std::shared_ptr<Base> makeFinder(Int2Type<TYPE1>) { return std::make_shared<Find1>(); }
    std::shared_ptr<Base> makeFinder(Int2Type<TYPE2>) { return std::make_shared<Find2>(); }
    std::shared_ptr<Base> makeFinder(Int2Type<TYPE3>) { return std::make_shared<Find3>(); }

   public:
    std::shared_ptr<Base> makeFinder() { return makeFinder(Int2Type<type>()); }
};

TEST(Template, StaticDispatch)
{
    auto s1 = findBuilder<TYPE1>().makeFinder();
    TStaticDispatchTest::FindDriver::process(s1);
    s1->FPrint();
    int driver1 = s1->GetD();
    int receiver1 = s1->GetR();

    auto s2 = findBuilder<TYPE2>().makeFinder();
    TStaticDispatchTest::FindDriver::process(s2);
    s2->FPrint();
    int driver2 = s2->GetD();
    int receiver2 = s2->GetR();
}
};  // namespace TStaticDispatchTest

namespace TStaticDispatchTest2 {
enum WAYS { TYPE1, TYPE2, TYPE3 };

template <typename T>
struct Type2Type {
    typedef T OriginalType;
};

class Pattern {
   public:
    Pattern() = default;
    virtual void Process() {}
    virtual void FPrint() { std::cout << "d = " << d << ", r = " << r << std::endl; }

   public:
    virtual int &GetD() final { return d; }
    virtual int &GetR() final { return r; }

   private:
    int d{0};
    int r{0};
};

// template <int type>
class FindPattern {
   public:
    static void process(std::shared_ptr<Pattern> obj) { obj->Process(); }
};

class FindPattern1 : public Pattern {
   public:
    FindPattern1() = default;
    void FPrint() override
    {
        Pattern::FPrint();
        std::cout << "this is TYPE1" << std::endl;
    }
    void Process() override
    {
        GetD() = 11;
        GetR() = 11;
    }
};

class FindPattern2 : public Pattern {
   public:
    FindPattern2() = default;
    void FPrint() override
    {
        Pattern::FPrint();
        std::cout << "this is TYPE2" << std::endl;
    }
    void Process() override
    {
        GetD() = 22;
        GetR() = 22;
    }
};

class FindPattern3 : public Pattern {
   public:
    FindPattern3() = default;
    void FPrint() override
    {
        Pattern::FPrint();
        std::cout << "this is TYPE3" << std::endl;
    }
    void Process() override
    {
        GetD() = 33;
        GetR() = 33;
    }
};

template <typename T>
class findBuilder {
   private:
    std::shared_ptr<Pattern> makeFinder(Type2Type<T>) { return std::make_shared<T>(); }

   public:
    std::shared_ptr<Pattern> makeFinder() { return makeFinder(Type2Type<T>()); }
};

TEST(Template, StaticDispatch)
{
    auto s1 = findBuilder<FindPattern1>().makeFinder();
    TStaticDispatchTest2::FindPattern::process(s1);
    s1->FPrint();
    int driver1 = s1->GetD();
    int receiver1 = s1->GetR();

    auto s2 = findBuilder<FindPattern2>().makeFinder();
    TStaticDispatchTest2::FindPattern::process(s2);
    s2->FPrint();
    int driver2 = s2->GetD();
    int receiver2 = s2->GetR();
}
};  // namespace TStaticDispatchTest2