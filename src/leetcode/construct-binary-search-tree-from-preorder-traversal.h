// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

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
    void insertIntoBST(TreeNode** node, const int& val) {
        if (*node == nullptr) {
            *node = new TreeNode(val);
            return;
        }

        insertIntoBST((val < (*node)->val) ? &(*node)->left : &(*node)->right, val);
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root{ nullptr };
        for (auto& val : preorder)
            insertIntoBST(&root, val);
        return root;
    }
};