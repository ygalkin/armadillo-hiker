// https://leetcode.com/problems/binary-tree-paths/

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
    vector<string> _paths;
public:
    void preorder_bst(const TreeNode* node, string path) {
        if (node == nullptr) {
            return;
        }

        if (!path.empty())  path += "->";
        path += to_string(node->val);

        if (node->left || node->right) {
            preorder_bst(node->left, path);
            preorder_bst(node->right, path);
        }
        else {
            // a leaf node
            _paths.push_back(path);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        _paths.clear();

        string path;
        preorder_bst(root, path);

        return _paths;
    }
};