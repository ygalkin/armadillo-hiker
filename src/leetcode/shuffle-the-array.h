// https://leetcode.com/problems/shuffle-the-array/ 

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ret;

        for (auto i = 0; i < n; ++i) {
            ret.push_back(nums[i]);
            ret.push_back(nums[i + n]);
        }

        return ret;
    }
};