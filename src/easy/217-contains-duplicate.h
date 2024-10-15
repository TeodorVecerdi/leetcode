#pragma once

#include <bits/stdc++.h>
#include "problem_runner.h"

inline bool solve(std::vector<int32_t>& nums) {
    std::ranges::sort(nums);
    for (size_t i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) {
            return true;
        }
    }

    return false;
}

DEFINE_PROBLEM(ContainsDuplicate, std::vector<int32_t>, bool) {
    return solve(const_cast<std::vector<int32_t>&>(input));
})

TEST_CASE(L({1,2,3,1}), true)
TEST_CASE(L({1,2,3,4}), false)
TEST_CASE(L({1,1,1,3,3,4,3,2,4,2}), true)

BUILD_PROBLEM;
