// https://leetcode.com/problems/reverse-string/

class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.empty()) {
            return;
        }
        const auto size = s.size();
        for (auto i = 0; i < size / 2; ++i) {
            std::swap(s[i], s[size - i - 1]);
        }
    }
};