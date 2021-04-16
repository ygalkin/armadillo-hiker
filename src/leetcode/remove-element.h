// https://leetcode.com/problems/remove-element/

class Solution {
public:
    // Single array pass. Array in-place modification. Two-pointer solution.
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) {
            return 0;
        }
        const auto size = nums.size();
        int i{ 0 };
        int j = size - 1;

        while (i <= j) {
            if (nums[i] == val) {
                if (nums[j] != val) {
                    std::swap(nums[i], nums[j]);
                    i++;
                    --j;
                    continue;
                }
                --j;
                continue;
            }

            ++i;
        }

        return i;
    }
};
