#pragma once


template<typename T>
struct BinaryTree {
    T val;
    BinaryTree* left = nullptr;
    BinaryTree* right = nullptr;

    BinaryTree()
        : val({}), left(nullptr), right(nullptr) {
    }

    explicit BinaryTree(T x)
        : val(x), left(nullptr), right(nullptr) {
    }

    BinaryTree(T x, BinaryTree* left, BinaryTree* right)
        : val(x), left(left), right(right) {
    }

public:
    static BinaryTree* create(const std::vector<std::optional<T>>& nodes) {
        if (nodes.empty() || !nodes[0].has_value())
            return nullptr;

        auto* root = new BinaryTree(nodes[0].value());
        std::queue<BinaryTree*> q;
        q.push(root);

        for (size_t i = 1; i < nodes.size(); i += 2) {
            BinaryTree* current = q.front();
            q.pop();

            if (i < nodes.size() && nodes[i].has_value()) {
                current->left = new BinaryTree(nodes[i].value());
                q.push(current->left);
            }

            if (i + 1 < nodes.size() && nodes[i + 1].has_value()) {
                current->right = new BinaryTree(nodes[i + 1].value());
                q.push(current->right);
            }
        }

        return root;
    }

    static void free(BinaryTree* root) {
        if (root == nullptr)
            return;
        free(root->left);
        free(root->right);
        delete root;
    }
};
