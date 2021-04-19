// https://leetcode.com/problems/average-of-levels-in-binary-tree/

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
    vector<double> averageOfLevels(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<double> ret;
        vector<TreeNode*> q;

        q.push_back(root);
        while (!q.empty()) {
            const auto size = q.size(); // because we change q size in the loop
            double sum{ 0 };
            for (auto i = 0; i < size; ++i) {
                const auto node = q[i];
                sum += node->val;
                if (node->left) q.push_back(node->left);
                if (node->right) q.push_back(node->right);
            }

            ret.push_back(sum / size);
            q.erase(begin(q), begin(q) + size);
        }

        return ret;
    }
};
