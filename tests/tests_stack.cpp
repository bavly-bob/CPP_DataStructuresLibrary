#include "stack.h"
#include "tests_stack.h"

#include <cassert>
#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <stdexcept>
#include <utility>

// -------------------- Basic Operations --------------------
void tests_stack::test_basic_operations()
{
    ds::Stack<int> s;

    assert(s.isEmpty());
    assert(s.size() == 0);

    s.push(10);
    assert(!s.isEmpty());
    assert(s.size() == 1);
    assert(s.top() == 10);

    s.push(20);
    assert(s.size() == 2);
    assert(s.top() == 20);

    s.pop();
    assert(s.size() == 1);
    assert(s.top() == 10);

    s.pop();
    assert(s.isEmpty());
}

// -------------------- Boundary Conditions --------------------
void tests_stack::test_boundary_conditions()
{
    ds::Stack<int> s;

    bool thrown = false;
    try {
        s.pop();
    } catch (const std::underflow_error&) {
        thrown = true;
    }
    assert(thrown);

    thrown = false;
    try {
        s.top();
    } catch (const std::underflow_error&) {
        thrown = true;
    }
    assert(thrown);

    s.push(1);
    s.pop();
    assert(s.isEmpty());
}

// -------------------- Template Type Coverage --------------------
struct Point 
{
    int x, y;
};

void tests_stack::test_template_types()
{
    ds::Stack<int> si;
    si.push(1);
    assert(si.top() == 1);

    ds::Stack<double> sd;
    sd.push(3.14);
    assert(sd.top() == 3.14);

    ds::Stack<std::string> ss;
    ss.push("hello");
    assert(ss.top() == "hello");

    ds::Stack<char> sc;
    sc.push('A');
    assert(sc.top() == 'A');

    ds::Stack<bool> sb;
    sb.push(true);
    assert(sb.top());

    ds::Stack<Point> sp;
    sp.push({1, 2});
    assert(sp.top().x == 1 && sp.top().y == 2);
}

// -------------------- Sequential Stress --------------------
void tests_stack::test_stress_sequential()
{
    ds::Stack<int> s;
    constexpr int N = 100;

    for (int i = 0; i < N; ++i)
        s.push(i);

    assert(s.size() == N);

    for (int i = N - 1; i >= 0; --i) {
        assert(s.top() == i);
        s.pop();
    }

    assert(s.isEmpty());
}

// -------------------- Randomized Stress --------------------
void tests_stack::test_randomized_operations()
{
    ds::Stack<int> s;
    std::vector<int> mirror;

    std::mt19937 rng(42);
    std::uniform_int_distribution<int> action(0, 1);

    constexpr int OPS = 1000;

    for (int i = 0; i < OPS; ++i) {
        if (action(rng) == 0 || mirror.empty()) {
            int val = rng() % 1000;
            s.push(val);
            mirror.push_back(val);
        } else {
            assert(s.top() == mirror.back());
            s.pop();
            mirror.pop_back();
        }
    }

    assert(s.size() == mirror.size());
}

// -------------------- Copy & Assignment --------------------
void tests_stack::test_copy_and_assignment()
{
    ds::Stack<int> s1;
    s1.push(1);
    s1.push(2);

    ds::Stack<int> s2(s1);
    assert(s2.top() == 2);

    s2.pop();
    assert(s1.top() == 2);

    ds::Stack<int> s3;
    s3 = s1;
    assert(s3.top() == 2);

    s3.pop();
    assert(s1.top() == 2);

    s1 = s1;
    assert(s1.top() == 2);
}

// -------------------- Move Semantics --------------------
void tests_stack::test_move_semantics()
{
    ds::Stack<int> s1;
    s1.push(1);
    s1.push(2);

    ds::Stack<int> s2(std::move(s1));
    assert(s2.size() == 2);
    assert(s2.top() == 2);

    ds::Stack<int> s3;
    s3 = std::move(s2);
    assert(s3.size() == 2);
    assert(s3.top() == 2);
}

// -------------------- Large Scale --------------------
void tests_stack::test_large_scale()
{
    ds::Stack<int> s;
    constexpr int N = 100000;

    for (int i = 0; i < N; ++i)
        s.push(i);

    for (int i = 0; i < N; ++i)
        s.pop();

    assert(s.isEmpty());
}
