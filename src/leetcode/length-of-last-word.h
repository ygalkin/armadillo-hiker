// https://leetcode.com/problems/length-of-last-word/

class Solution {
public:
    int lengthOfLastWord(string s) {
        auto len{ 0 };
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] != ' ') ++len;
            if (len > 0 && s[i] == ' ') break;
        }

        return len;
    }
};