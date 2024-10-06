#pragma once

#include <bits/stdc++.h>
#include "../problem_runner.h"

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(const int x) :
        val(x), left(nullptr), right(nullptr) {
    }
};

// Function to build tree from vector of optional ints
inline TreeNode* buildTree(const std::vector<std::optional<int>>& nodes) {
    if (nodes.empty() || !nodes[0].has_value())
        return nullptr;

    auto* root = new TreeNode(nodes[0].value());
    std::queue<TreeNode*> q;
    q.push(root);

    for (size_t i = 1; i < nodes.size(); i += 2) {
        TreeNode* current = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i].has_value()) {
            current->left = new TreeNode(nodes[i].value());
            q.push(current->left);
        }

        if (i + 1 < nodes.size() && nodes[i + 1].has_value()) {
            current->right = new TreeNode(nodes[i + 1].value());
            q.push(current->right);
        }
    }

    return root;
}

// Function to delete the tree (to prevent memory leaks)
inline void deleteTree(const TreeNode* root) {
    if (root == nullptr)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

inline size_t dfs(const TreeNode* node, size_t& maxDiameter) {
    if (node == nullptr)
        return 0;

    const size_t leftHeight = dfs(node->left, maxDiameter);
    const size_t rightHeight = dfs(node->right, maxDiameter);

    maxDiameter = std::max(maxDiameter, leftHeight + rightHeight);

    return std::max(leftHeight, rightHeight) + 1;
}

inline size_t solve(const TreeNode* root) {
    size_t maxDiameter = 0;
    dfs(root, maxDiameter);
    return maxDiameter;
}

// Given the root of a binary tree, return the length of the diameter of the tree.
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
// This path may or may not pass through the root.
DEFINE_PROBLEM(DiameterOfBinaryTree, std::vector<std::optional<int>>, size_t) {
    const TreeNode* root = buildTree(input);
    const size_t result = solve(root);
    deleteTree(root);
    return result;
})

TEST_CASE(L({1,2,3,4,5}), 3)
TEST_CASE(L({1,2}), 1)
TEST_CASE(L({1}), 0)
TEST_CASE(L({1,2,3,4,5,std::nullopt,std::nullopt,6,7}), 4)

BUILD_PROBLEM;
