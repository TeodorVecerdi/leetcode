#pragma once

#include <bits/stdc++.h>
#include "problem_runner.h"

inline size_t solve(const std::vector<int32_t>& input) {
    size_t seconds = 0;
    std::priority_queue queue { input.begin(), input.end() };

    while (queue.top() != 0) {
        seconds++;

        const int32_t a = queue.top();
        queue.pop();
        const int32_t b = queue.top();
        queue.pop();

        queue.push(a - 1);
        queue.push(b - 1);
    }

    return seconds;
}

DEFINE_PROBLEM(MinimumAmountOfTimeToFillCups, std::vector<int32_t>, size_t) {
    return solve(input);
})

TEST_CASE(L({1,4,2}), 4)
TEST_CASE(L({5,4,4}), 7)
TEST_CASE(L({5,0,0}), 5)

BUILD_PROBLEM;
