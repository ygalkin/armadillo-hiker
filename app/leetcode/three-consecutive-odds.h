// https://leetcode.com/problems/three-consecutive-odds/ 

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for (int i = 0; i <= static_cast<int>(arr.size()) - 3; ++i) {
            if ((arr[i] % 2) && (arr[i + 1] % 2) && (arr[i + 2] % 2))
                return true;
        }

        return false;
    }
};