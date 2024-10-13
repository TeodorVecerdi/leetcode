#pragma once

#include <bits/stdc++.h>
#include "problem_runner.h"

// You are given two non-negative integers num1 and num2.
//
// In one operation, if num1 >= num2, you must subtract num2 from num1, otherwise subtract num1 from num2.
//
// • For example, if num1 = 5 and num2 = 4, subtract num2 from num1, thus obtaining num1 = 1 and num2 = 4.
//   However, if num1 = 4 and num2 = 5, after one operation, num1 = 4 and num2 = 1.
//
// Return the number of operations required to make either num1 = 0 or num2 = 0.

inline size_t solve(int32_t a, int32_t b) {
    if (a == 0 || b == 0) return 0;
    size_t operations = 0;

    while (a != 0 && b != 0) {
        if (a >= b) {
            a -= b;
        } else {
            b -= a;
        }

        ++operations;
    }

    return operations;
}

DEFINE_PROBLEM(CountOperationsToObtainZero, L(std::pair<int32_t, int32_t>), size_t) {
    const auto [a, b] = input;
    return solve(a, b);
})

TEST_CASE(L({2, 3}), 3)
TEST_CASE(L({10, 10}), 1)

BUILD_PROBLEM;
