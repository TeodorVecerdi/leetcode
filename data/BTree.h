#pragma once


template<typename T>
struct BTreeNode {
    T val;
    BTreeNode* left = nullptr;
    BTreeNode* right = nullptr;

    BTreeNode()
        : val({}), left(nullptr), right(nullptr) {
    }

    explicit BTreeNode(T x)
        : val(x), left(nullptr), right(nullptr) {
    }

    BTreeNode(T x, BTreeNode* left, BTreeNode* right)
        : val(x), left(left), right(right) {
    }

public:
    static BTreeNode* create(const std::vector<std::optional<T>>& nodes) {
        if (nodes.empty() || !nodes[0].has_value())
            return nullptr;

        auto* root = new BTreeNode(nodes[0].value());
        std::queue<BTreeNode*> q;
        q.push(root);

        for (size_t i = 1; i < nodes.size(); i += 2) {
            BTreeNode* current = q.front();
            q.pop();

            if (i < nodes.size() && nodes[i].has_value()) {
                current->left = new BTreeNode(nodes[i].value());
                q.push(current->left);
            }

            if (i + 1 < nodes.size() && nodes[i + 1].has_value()) {
                current->right = new BTreeNode(nodes[i + 1].value());
                q.push(current->right);
            }
        }

        return root;
    }

    static void free(BTreeNode* root) {
        if (root == nullptr)
            return;
        free(root->left);
        free(root->right);
        delete root;
    }
};
