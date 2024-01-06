//
// Created by gqxiong on 2024/1/5.
//

#include "gtest/gtest.h"

// 测试 false path

class Clock {
   public:
    Clock(std::string &&name, int domain)
    {
        _name = std::move(name);
        _domain = domain;
    }

   private:
    std::string _name;
    int _domain;
};

using ClockList = std::set<Clock *>;

class CircuitObj {
   public:
    CircuitObj(std::string &&name) { _name = std::move(name); }

    void SetClock(ClockList &&clock) { _clock = std::move(clock); }

   private:
    std::string _name;
    ClockList _clock;
};

class FalseManager {
   public:
    // 获取单实例对象
    static FalseManager &GetInstance()
    {
        static FalseManager single;
        return single;
    }

   private:
    FalseManager() {}
    ~FalseManager() {}
    FalseManager(const FalseManager &single) = delete;
    const FalseManager &operator=(const FalseManager &single) = delete;

   public:
    bool IfNeedIgnore(CircuitObj *from, CircuitObj *to, const ClockList &fromClock, const ClockList &toClock) {}

    void SetFalsePath(CircuitObj *from, CircuitObj *to, ClockList &&fromClock, ClockList &&toClock)
    {
        _from = from;
        _to = to;
        _fromClock = std::move(fromClock);
        _toClock = std::move(toClock);
    }

   private:
    CircuitObj *_from{nullptr};
    CircuitObj *_to{nullptr};
    ClockList _fromClock{};
    ClockList _toClock{};
};

void FalsePathCommandProcess()
{
    CircuitObj c1{"c1"};
    CircuitObj c2{"c2"};
    ClockList cl1{new Clock("clk1", 1), new Clock("clk2", 2)};
    ClockList cl2{new Clock("clk1", 1), new Clock("clk3", 1)};

    FalseManager::GetInstance().SetFalsePath(&c1, &c2, std::move(cl1), std::move(cl2));
}

TEST(FALSEPATH, test1)
{
    // pair <v1, v2>
    CircuitObj c1{"c1"};
    CircuitObj c2{"c2"};
    ClockList cl1{new Clock("clk1", 1), new Clock("clk2", 2)};
    ClockList cl2{new Clock("clk1", 1), new Clock("clk3", 1)};
    c1.SetClock(std::move(cl1));
    c2.SetClock(std::move(cl2));

    FalsePathCommandProcess();
}
