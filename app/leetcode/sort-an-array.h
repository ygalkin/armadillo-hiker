// https://leetcode.com/problems/sort-an-array/

// Selection sort

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for (auto iter = begin(nums); iter != end(nums); ++iter) {
            iter_swap(iter, min_element(iter, end(nums)));
        }
        return nums;
    }
};