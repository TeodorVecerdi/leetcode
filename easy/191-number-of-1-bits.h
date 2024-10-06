#pragma once

#include <bits/stdc++.h>
#include "../problem_runner.h"

// Write a function that takes the binary representation of a positive integer and returns the number of '1' bits it has (also known as the Hamming weight).

DEFINE_PROBLEM(NumberOf1Bits, uint32_t, int) {
    uint32_t n = input;
    int32_t count = 0;
    while (n != 0) {
        count += static_cast<int32_t>(n & 1);
        n >>= 1;
    }

    return count;
})

TEST_CASE(11, 3)
TEST_CASE(128, 1)
TEST_CASE(2147483645, 30)
TEST_CASE(0, 0)
TEST_CASE(UINT32_MAX, 32)

BUILD_PROBLEM;