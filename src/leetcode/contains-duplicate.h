// https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> lookup_tbl;
        for (auto i : nums) {
            if (!lookup_tbl.insert(i).second) { // No isertion. Item already in the lookup table. 
                return true;
            }
        }
        return false;
    }
};
