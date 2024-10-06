#pragma once

#include <bits/stdc++.h>
#include "../problem_runner.h"

// You are given a 0-indexed integer array nums.
// In one operation you can replace any element of the array with any two elements that sum to it.
// Return the minimum number of operations to make an array that is sorted in non-decreasing order.

inline size_t solve(const std::vector<int>& nums) {
    const size_t n = nums.size();
    size_t result = 0;
    int64_t prev = nums[n-1];

    for (int64_t i = n - 2; i >= 0; --i) {
        if (nums[i] <= prev) {
            prev = nums[i];
            continue;
        }

        // Calculate how many pieces we need to split nums[i] into
        int64_t pieces = (nums[i] + prev - 1) / prev;

        // Number of operations needed == pieces - 1
        result += pieces - 1;

        // Update the value of the current element after splitting
        prev = nums[i] / pieces;
    }

    return result;
}

DEFINE_PROBLEM(MinimumReplacements, std::vector<int>, uint64_t) {
    return solve(input);
})

TEST_CASE(L({3,9,3}), 2)
TEST_CASE(L({1,2,3,4,5}), 0)
TEST_CASE(L({10,5,15,20}), 1)
TEST_CASE(L({5,4,3,2,1}), 10)
TEST_CASE(L({2,2,2,2,2}), 0)

BUILD_PROBLEM;