// https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> lookup_tbl;
        for (const auto n : nums) {
            auto it = lookup_tbl.insert(n);
            if (!it.second) { // no insertion. n is already in the lookup table
                return n;
            }
        }
        return -1;
    }
};