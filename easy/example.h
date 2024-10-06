#pragma once

#include <numeric>
#include "../problem_runner.h"

DEFINE_PROBLEM(SumOfSquares, std::vector<int>, int) {
    return std::accumulate(input.begin(), input.end(), 0, [](const int sum, const int val) {
        return sum + val * val;
    });
}
END_PROBLEM
TEST_CASE(L({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}), 384)
TEST_CASE(L({1, 2, 3, 4}), 30)
TEST_CASE(L({}), 0)
BUILD_PROBLEM;
