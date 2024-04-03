//
// Created by gqxiong on 2024/1/5.
//

#include "gtest/gtest.h"

// 测试 false path

class Clock {
   public:
    Clock(std::string &&name, int id)
    {
        _name = std::move(name);
        _id = id;
    }

   public:
    std::string _name;
    int _id;
};

using ClockVec = std::vector<Clock *>;

bool IsCrossing(const ClockVec &v1, const ClockVec &v2)
{
    std::set<int> ids1{};
    std::set<int> ids2{};

    for (const auto &clk1 : v1) {
        ids1.insert(clk1->_id);
    }

    for (const auto &clk2 : v2) {
        ids2.insert(clk2->_id);
    }

    if (ids1.size() == ids2.size()) {
        for (auto &id1 : ids1) {
            erase_if(ids2, [&](const auto &id) -> bool { return id1 == id; });
        }
    } else {
        return true;
    }

    return !ids2.empty();
}

class CircuitObj {
   public:
    CircuitObj(std::string &&name) { _name = std::move(name); }

    void SetClock(ClockVec &&clock) { _clock = std::move(clock); }

    std::string& GetName() {
        return _name;
    }
   private:
    std::string _name;
    ClockVec _clock;
};

class FalseManager {
   public:
    // 获取单实例对象
    static FalseManager &GetInstance()
    {
        static FalseManager single;
        return single;
    }
    FalseManager() = default;
    ~FalseManager() = default;
    FalseManager(const FalseManager &single) = delete;

   private:
    const FalseManager &operator=(const FalseManager &single) = delete;

   public:
    bool IfNeedIgnore(CircuitObj *from, CircuitObj *to, const ClockVec &fromClock, const ClockVec &toClock)
    {
        bool isMatched = false;
        if (!_from || (from->GetName() == _from->GetName())) {
            isMatched = true;
        }
        if (!_to || (to->GetName() == _to->GetName())) {
            isMatched = true;
        }
        if (_fromClock.empty() || !(IsCrossing(fromClock, _fromClock))) {
            isMatched = true;
        }
        if (_toClock.empty() || !(IsCrossing(toClock, _toClock))) {
            isMatched = true;
        }

        return isMatched;
    }

    void SetFalsePath(CircuitObj *from, CircuitObj *to, ClockVec &&fromClock, ClockVec &&toClock)
    {
        _from = from;
        _to = to;
        _fromClock = std::move(fromClock);
        _toClock = std::move(toClock);
    }

   private:
    CircuitObj *_from{nullptr};
    CircuitObj *_to{nullptr};
    ClockVec _fromClock{};
    ClockVec _toClock{};
};

void FalsePathCommandProcess()
{
    CircuitObj c1{"c1"};
    CircuitObj c2{"c2"};
    ClockVec cl1{new Clock("clk1", 1), new Clock("clk2", 2)};
    ClockVec cl2{new Clock("clk1", 1), new Clock("clk3", 1)};

    FalseManager::GetInstance().SetFalsePath(&c1, &c2, std::move(cl1), std::move(cl2));
}

TEST(FALSEPATH, test1)
{
    // pair <v1, v2>
    CircuitObj c1{"c1"};
    CircuitObj c2{"c2"};
    ClockVec cl1{new Clock("clk1", 1), new Clock("clk2", 2)};
    ClockVec cl2{new Clock("clk1", 1), new Clock("clk3", 1)};
    c1.SetClock(std::move(cl1));
    c2.SetClock(std::move(cl2));

    FalsePathCommandProcess();

    std::cout << "result = " << FalseManager::GetInstance().IfNeedIgnore(&c1, &c2, cl1, cl2) << std::endl;
}
