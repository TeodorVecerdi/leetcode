#pragma once

#include <bits/stdc++.h>
#include "problem_runner.h"
#include "data/BinaryTree.h"

inline int64_t solve(BinaryTree<int32_t>* tree, const int32_t k) {
    std::vector<int64_t> sums{};
    std::queue<std::pair<BinaryTree<int32_t>*, int32_t>> queue{};

    queue.emplace(tree, 0);
    while (!queue.empty()) {
        const auto [node, depth] = queue.front();
        queue.pop();

        // Make sure `sums` has enough elements to index at `depth`
        while (sums.size() <= depth)
            sums.push_back(0);

        // Update the sum at `depth`
        sums[depth] += node->val;

        // Traverse the left and right children
        if (node->left)
            queue.emplace(node->left, depth + 1);
        if (node->right)
            queue.emplace(node->right, depth + 1);
    }

    if (sums.size() < k)
        return -1;

    std::ranges::sort(sums, std::ranges::greater{});
    return sums[k - 1];
}

DEFINE_PROBLEM(KthLargestSumInBinaryTree, L(std::pair<std::vector<std::optional<int32_t>>, int32_t>), int64_t) {
    const auto& [tree, k] = input;
    BinaryTree<int32_t>* root = BinaryTree<int32_t>::create(tree);
    const int64_t result = solve(root, k);
    BinaryTree<int32_t>::free(root);
    return result;
})

TEST_CASE(L({{5, 8, 9, 2, 1, 3, 7, 4, 6}, 2}), 13)
TEST_CASE(L({{1, 2, std::nullopt, 3}, 1}), 3)

BUILD_PROBLEM;
