// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/ 

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> ret;
        vector<TreeNode*> q;

        q.push_back(root);
        while (!q.empty()) {
            const auto size = q.size(); // because we change q size in the loop
            vector<int> level;
            for (auto i = 0; i < size; ++i) {
                const auto node = q[i];
                if (node->left) q.push_back(node->left);
                if (node->right) q.push_back(node->right);
                level.push_back(node->val);
            }

            ret.push_back(level);
            q.erase(begin(q), begin(q) + size);
        }

        reverse(begin(ret), end(ret));
        return ret;
    }
};