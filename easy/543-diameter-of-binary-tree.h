#pragma once

#include <bits/stdc++.h>

#include "problem_runner.h"
#include "data/BTree.h"

inline size_t dfs(const BTreeNode<int32_t>* node, size_t& maxDiameter) {
    if (node == nullptr)
        return 0;

    const size_t leftHeight = dfs(node->left, maxDiameter);
    const size_t rightHeight = dfs(node->right, maxDiameter);

    maxDiameter = std::max(maxDiameter, leftHeight + rightHeight);

    return std::max(leftHeight, rightHeight) + 1;
}

inline size_t solve(const BTreeNode<int32_t>* root) {
    size_t maxDiameter = 0;
    dfs(root, maxDiameter);
    return maxDiameter;
}

// Given the root of a binary tree, return the length of the diameter of the tree.
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
// This path may or may not pass through the root.
DEFINE_PROBLEM(DiameterOfBinaryTree, std::vector<std::optional<int>>, size_t) {
    BTreeNode<int32_t>* root = BTreeNode<int32_t>::create(input);
    const size_t result = solve(root);
    BTreeNode<int32_t>::free(root);
    return result;
})

TEST_CASE(L({1,2,3,4,5}), 3)
TEST_CASE(L({1,2}), 1)
TEST_CASE(L({1}), 0)
TEST_CASE(L({1,2,3,4,5,std::nullopt,std::nullopt,6,7}), 4)

BUILD_PROBLEM;
