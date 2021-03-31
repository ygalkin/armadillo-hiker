// https://leetcode.com/problems/plus-one/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto n = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            n += digits[i];
            auto reminder = (n % 10);
            n = n / 10;
            digits[i] = reminder;
        }
        
        if (n > 0) {
            digits.insert(begin(digits), n);
        }
        
        return digits;
    }
};