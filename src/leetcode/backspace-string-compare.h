// https://leetcode.com/problems/backspace-string-compare/

class Solution {
public:
    string process_string(const string& str) {
        std::string s;

        for (const auto& ch : str) {
            if (ch != '#')
                s.push_back(ch);
            else if (!s.empty())
                s.pop_back();
        }

        return s;
    }

    bool backspaceCompare(string s, string t) {
        return process_string(s) == process_string(t);
    }
};
