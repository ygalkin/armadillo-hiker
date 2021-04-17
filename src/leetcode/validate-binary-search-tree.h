// https://leetcode.com/problems/validate-binary-search-tree/

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
public:
    bool is_bst(TreeNode* node, TreeNode* min, TreeNode* max) {
        if (node == nullptr) {
            return true;
        }

        if ((min && node->val <= min->val) || (max && node->val >= max->val)) {
            return false;
        }

        return is_bst(node->left, min, node) && is_bst(node->right, node, max);
    }

    bool isValidBST(TreeNode* root) {
        return is_bst(root, nullptr, nullptr);
    }
};