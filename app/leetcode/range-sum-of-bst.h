// https://leetcode.com/problems/range-sum-of-bst/

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr)
            return 0;

        auto sum{ 0 };

        if (low < root->val)
            sum += rangeSumBST(root->left, low, high);

        if (high > root->val)
            sum += rangeSumBST(root->right, low, high);

        if (root->val >= low && root->val <= high)
            sum += root->val;

        return sum;
    }
};