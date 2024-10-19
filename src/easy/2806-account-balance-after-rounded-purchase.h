#pragma once

#include <bits/stdc++.h>
#include "problem_runner.h"

inline int32_t solve(int32_t input) {
    const int32_t rem = input % 10;
    input -= rem;
    if (rem >= 5)
        input += 10;

    return 100 - input;
}

DEFINE_PROBLEM(AccountBalanceAfterRoundedPurchase, int32_t, int32_t) {
    return solve(input);
})

TEST_CASE(9, 90)
TEST_CASE(15, 80)
TEST_CASE(10, 90)

BUILD_PROBLEM;
