// https://leetcode.com/problems/binary-tree-inorder-traversal/

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
    void inorder_bst(const TreeNode* node, vector<int>& vals) const {
        if (node == nullptr)
            return;

        inorder_bst(node->left, vals);
        vals.push_back(node->val);
        inorder_bst(node->right, vals);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        inorder_bst(root, ret);
        return ret;
    }
};