// https://www.hackerrank.com/challenges/balanced-brackets/problem

// Complete the isBalanced function below.
string isBalanced(string s) {
    const unordered_map<char, char> _matcher = {
        {'(', ')'},
        {'[', ']'},
        {'{', '}'}
    };

    stack<char> stack;

    for (const auto& bracket : s) {
        if (_matcher.count(bracket) > 0) { // if this is an open bracket
            // push it into the stack
            stack.push(bracket);
        }
        else { // if this is a close bracket
            if (stack.empty())
                return "NO";

            // pop the first bracket (open) from the stack
            const auto open_bracket = stack.top();
            stack.pop();

            // try to match them
            if (_matcher.at(open_bracket) != bracket)
                return "NO";
        }
    }

    return stack.empty() ? "YES" : "NO";
}