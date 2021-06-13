// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        size_t unique{ 0 };

        for (size_t i{ 1 }; i < nums.size(); ++i) {
            if (nums[i] != nums[unique]) {
                ++unique;
                nums[unique] = nums[i];
            }
        }

        return unique + 1;
    }
};
