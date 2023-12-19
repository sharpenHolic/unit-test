//
// Created by gqxiong on 2023/12/7.
//
#include "gtest/gtest.h"

template <class Fun>
class utScopeGuard {
    Fun _f;
    bool _active;

public:
    utScopeGuard(Fun f) : _f(std::move(f)), _active(true) {}

    ~utScopeGuard()
    {
        if (_active)
            _f();
    }
    void GuardOn() { _active = true; }
    void GuardOff() { _active = false; }

    utScopeGuard() = delete;
    utScopeGuard(const utScopeGuard&) = delete;
    utScopeGuard& operator=(const utScopeGuard&) = delete;

    utScopeGuard(utScopeGuard&& rhs) : _f(std::move(rhs._f)), _active(rhs._active) {}
};

// Type deduction
template <class Fun>
utScopeGuard<Fun> utScopeGuardFunc(Fun f)
{
    return utScopeGuard<Fun>(std::move(f));
}

TEST(SMARTPOINT, TEST1) {
    auto i = new int(10);
    auto sg = utScopeGuard([&](){delete i;});
}