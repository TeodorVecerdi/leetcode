#pragma once

#include <bits/stdc++.h>
#include "problem_runner.h"

// Anti-theft security devices are activated inside a bank.
// You are given a 0-indexed binary string array bank representing the floor plan of the bank, which is an m x n 2D matrix.
// bank[i] represents the ith row, consisting of '0's and '1's.
// '0' means the cell is empty, while '1' means the cell has a security device.
//
// There is one laser beam between any two security devices if both conditions are met:
// • The two devices are located on two different rows: r1 and r2, where r1 < r2.
// • For each row i where r1 < i < r2, there are no security devices in the ith row.
//
// Laser beams are independent, i.e., one beam does not interfere nor join with another.
// Return the total number of laser beams in the bank.

inline size_t solve(const std::vector<std::string>& input) {
    if (input.empty()) {
        return 0;
    }

    size_t result = 0;
    size_t previous_row = std::ranges::count(input[0], '1');

    for (size_t i = 1; i < input.size(); ++i) {
        const size_t current_row = std::ranges::count(input[i], '1');
        if (current_row == 0) {
            continue;
        }

        result += previous_row * current_row;
        previous_row = current_row;
    }

    return result;
}

DEFINE_PROBLEM(NumberOfLaserBeamsInBank, std::vector<std::string>, size_t) {
    return solve(input);
})

TEST_CASE(L({"011001","000000","010100","001000"}), 8)
TEST_CASE(L({"000","111","000"}), 0)

BUILD_PROBLEM;
