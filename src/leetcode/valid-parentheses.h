// https://leetcode.com/problems/valid-parentheses/

class Solution {
private:
    const unordered_map<char, char> _matcher = {
        {'(', ')'},
        {'[', ']'},
        {'{', '}'}
    };
public:
    bool isValid(string s) {
        stack<char> stack;

        for (const auto& bracket : s) {
            if (_matcher.count(bracket) > 0) { // if this is an open bracket
                // push it into the stack
                stack.push(bracket);
            }
            else { // if this is a close bracket
                if (stack.empty())
                    return false;

                // pop the first bracket (open) from the stack
                const auto open_bracket = stack.top();
                stack.pop();

                // try to match them
                if (_matcher.at(open_bracket) != bracket)
                    return false;
            }
        }

        return stack.empty();
    }
};