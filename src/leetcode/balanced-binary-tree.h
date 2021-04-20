// https://leetcode.com/problems/balanced-binary-tree/

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
    // one pass, post-order
    bool is_balanced(const TreeNode* root, int& height) const {
        if (root == nullptr) {
            height = 0;
            return true;
        }

        auto lh{ 0 };
        auto rh{ 0 };
        if (!is_balanced(root->left, lh) || !is_balanced(root->right, rh))
            return false;

        height = std::max(lh, rh) + 1;

        return std::abs(lh - rh) <= 1;
    }

    bool isBalanced(TreeNode* root) {
        auto height{ 0 };
        return is_balanced(root, height);
    }
};