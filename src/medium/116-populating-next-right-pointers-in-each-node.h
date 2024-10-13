#pragma once

#include <bits/stdc++.h>
#include "problem_runner.h"

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node()
        : val(0), left(nullptr), right(nullptr), next(nullptr) {
    }

    explicit Node(const int val)
        : val(val), left(nullptr), right(nullptr), next(nullptr) {
    }

    Node(const int val, Node* left, Node* right, Node* next)
        : val(val), left(left), right(right), next(next) {
    }

    static Node* fromVector(const std::vector<std::optional<int>>& nums) {
        if (nums.empty() || !nums[0].has_value())
            return nullptr;

        // ReSharper disable once CppDFAMemoryLeak (false positive)
        auto* root = new Node(nums[0].value());
        std::queue<Node*> q;
        q.push(root);

        for (size_t i = 1; i < nums.size(); i += 2) {
            Node* current = q.front();
            q.pop();

            if (i < nums.size() && nums[i].has_value()) {
                current->left = new Node(nums[i].value());
                q.push(current->left);
            }

            if (i + 1 < nums.size() && nums[i + 1].has_value()) {
                current->right = new Node(nums[i + 1].value());
                q.push(current->right);
            }
        }

        return root;
    }

    static std::vector<std::optional<int>> toVector(Node* root) {
        if (!root)
            return {};

        std::vector<std::optional<int>> result;
        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current) {
                result.emplace_back(current->val);
                q.push(current->left);
                q.push(current->right);
            } else {
                result.emplace_back(std::nullopt);
            }
        }

        while (!result.empty() && !result.back().has_value()) {
            result.pop_back();
        }

        return result;
    }

    static void free(const Node* root) {
        if (!root)
            return;
        free(root->left);
        free(root->right);
        delete root;
    }
};

inline void set_next(const Node* node, std::array<Node*, 12>& pendingSetRight, const int32_t depth) {
    if (!node)
        return;

    if (pendingSetRight[depth] != nullptr) {
        pendingSetRight[depth]->next = node->left;
        pendingSetRight[depth] = nullptr;
    }

    if (node->left)
        node->left->next = node->right;
    pendingSetRight[depth] = node->right;

    set_next(node->left, pendingSetRight, depth + 1);
    set_next(node->right, pendingSetRight, depth + 1);
}

inline void solve(const Node* root) {
    std::array<Node*, 12> pendingSetRight{};
    set_next(root, pendingSetRight, 0);
}

inline Node* set_next2(const Node* node) {
    if (!node) {
        return nullptr;
    }

    if (node->left)
        node->left->next = node->right;

    if (Node* toSet = set_next2(node->left); toSet && node->right) {
        toSet->next = node->right->left;
    }

    set_next2(node->right);

    // caller should set next for the right child
    return node->right;
}

inline void solve2(const Node* root) {
    set_next2(root);
}

// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
// Initially, all next pointers are set to NULL.

DEFINE_PROBLEM(ConnectNextRightPointers, std::vector<std::optional<int>>, std::vector<std::optional<int>>) {
    Node* root = Node::fromVector(input);
    solve(root);

    std::vector<std::optional<int>> output = Node::toVector(root);
    Node::free(root);
    return output;
})

TEST_CASE(L({1,2,3,4,5,6,7}), L({1,2,3,4,5,6,7}))
TEST_CASE(L({}), L({}))
TEST_CASE(L({1}), L({1}))
TEST_CASE(L({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}), L({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}))

BUILD_PROBLEM;
