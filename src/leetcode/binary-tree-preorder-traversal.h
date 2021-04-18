// https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    void preorder_bst(const TreeNode* node, vector<int>& vals) const {
        if (node == nullptr)
            return;

        vals.push_back(node->val);
        preorder_bst(node->left, vals);
        preorder_bst(node->right, vals);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        preorder_bst(root, ret);
        return ret;
    }
};

// TODO: iterative solution