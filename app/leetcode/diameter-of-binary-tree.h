// https://leetcode.com/problems/diameter-of-binary-tree/submissions/ 

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

    int diameter_bst(const TreeNode* root, int& diameter) {
        if (root == nullptr) {
            return 0;
        }

        auto left = diameter_bst(root->left, diameter);
        auto right = diameter_bst(root->right, diameter);
        diameter = std::max(diameter, left + right);

        return std::max(left, right) + 1;

    }

    int diameterOfBinaryTree(TreeNode* root) {
        auto diameter{ 0 };
        diameter_bst(root, diameter);

        return diameter;
    }
};