// https://leetcode.com/problems/balance-a-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void for_each_node(TreeNode* parent, std::function<void(TreeNode*)> f) {
        if (parent == nullptr) {
            return;
        }

        for_each_node(parent->left, f);
        f(parent);
        for_each_node(parent->right, f);
    }

    TreeNode* reconstruct_tree(std::vector<TreeNode*>& nodes, size_t left, size_t right) {
        const size_t middle = left + ((right - left) / 2);
        TreeNode* current = nodes[middle];

        current->left = left == middle ? nullptr : reconstruct_tree(nodes, left, middle - 1);
        current->right = right == middle ? nullptr : reconstruct_tree(nodes, middle + 1, right);

        return current;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        std::vector<TreeNode*> nodes;
        for_each_node(root, [&nodes](auto i) { nodes.push_back(i); });
        return reconstruct_tree(nodes, 0, nodes.size() - 1);
    }
};