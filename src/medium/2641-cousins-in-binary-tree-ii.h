#pragma once

#include <bits/stdc++.h>
#include "problem_runner.h"
#include "data/BinaryTree.h"

inline void solve(BinaryTree<int32_t>* root) {
    using Node = std::pair<BinaryTree<int32_t>*, int32_t>;
    std::stack<Node> stack{};

    // Calculate the sum of each level
    stack.emplace(root, 0);
    std::vector<int32_t> sums{0};
    while (!stack.empty()) {
        const auto [node, level] = stack.top();
        stack.pop();

        while (sums.size() <= level)
            sums.push_back(0);
        sums[level] += node->val;

        if (node->left != nullptr)
            stack.emplace(node->left, level + 1);
        if (node->right != nullptr)
            stack.emplace(node->right, level + 1);
    }

    // Replace the value of each node with the sum of its level minus it's siblings' values
    root->val = 0;
    stack.emplace(root, 0);
    while (!stack.empty()) {
        const auto [node, level] = stack.top();
        stack.pop();

        // Store left value before updating it
        const int32_t leftVal = node->left ? node->left->val : 0;
        const int32_t rightVal = node->right ? node->right->val : 0;
        const int32_t levelSum = sums[level + 1];

        // Update the value of the left child
        if (node->left != nullptr) {
            node->left->val = levelSum - leftVal - rightVal;
            if (level < sums.size() - 2)
                stack.emplace(node->left, level + 1);
        }

        if (node->right != nullptr) {
            node->right->val = levelSum - leftVal - rightVal;
            if (level < sums.size() - 2)
                stack.emplace(node->right, level + 1);
        }
    }
}

DEFINE_PROBLEM(CousinsInBinaryTreeII, std::vector<std::optional<int32_t>>, std::vector<std::optional<int32_t>>) {
    BinaryTree<int32_t>* root = BinaryTree<int32_t>::create(input);
    solve(root);
    const auto result = BinaryTree<int32_t>::to_vector(root);
    BinaryTree<int32_t>::free(root);
    return result;
})

TEST_CASE(L({5,4,9,1,10,std::nullopt,7}), L({0,0,0,7,7,std::nullopt,11}))
TEST_CASE(L({3,1,2}), L({0,0,0}))

BUILD_PROBLEM;
