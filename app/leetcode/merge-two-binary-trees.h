// https://leetcode.com/problems/merge-two-binary-trees/

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
private:
    template <typename T>
    T safe_left_node(T ptr) {
        return (ptr ? ptr->left : nullptr);
    }

    template <typename T>
    T safe_right_node(T ptr) {
        return (ptr ? ptr->right : nullptr);
    }

    template <typename T, typename R = int>
    R safe_val_node(T ptr) {
        return (ptr ? ptr->val : 0);
    }

    TreeNode* tree_dfs(TreeNode* node1, TreeNode* node2) {
        if (node1 == nullptr && node2 == nullptr) {
            return nullptr;
        }

        TreeNode* new_node = new TreeNode(safe_val_node(node1) + safe_val_node(node2));

        new_node->left = tree_dfs(safe_left_node(node1), safe_left_node(node2));
        new_node->right = tree_dfs(safe_right_node(node1), safe_right_node(node2));

        return new_node;
    }

public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return tree_dfs(root1, root2);
    }
};