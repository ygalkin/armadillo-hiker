// https://leetcode.com/problems/binary-tree-postorder-traversal/

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
    void postorder_bst(const TreeNode* node, vector<int>& vals) const {
        if (node == nullptr)
            return;

        postorder_bst(node->left, vals);
        postorder_bst(node->right, vals);
        vals.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        postorder_bst(root, ret);
        return ret;
    }
};

// TODO: iterative solution