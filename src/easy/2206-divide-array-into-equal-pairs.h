#pragma once

#include <bits/stdc++.h>
#include "problem_runner.h"

inline bool solve(std::vector<int32_t>& nums) {
    std::ranges::sort(nums);
    for (size_t i = 0; i < nums.size(); i += 2) {
        if (nums[i] != nums[i + 1]) {
            return false;
        }
    }

    return true;
}

DEFINE_PROBLEM(DivideArrayIntoEqualPairs, std::vector<int32_t>, bool) {
    std::vector<int32_t> nums = input;
    return solve(nums);
})

TEST_CASE(L({3,2,3,2,2,2}), true)
TEST_CASE(L({1,2,3,4}), false)

BUILD_PROBLEM;
