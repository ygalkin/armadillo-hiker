// https://leetcode.com/problems/check-if-the-sentence-is-pangram/

class Solution {
private:
public:
    bool checkIfPangram(string sentence) {
        // Constraints: sentence consists of lowercase English letters.
        std::bitset<'z' - 'a' + 1> s;
        std::for_each(std::begin(sentence), std::end(sentence), [&s](auto& x) { s.set(x - 'a'); });
        return s.all();
    }
};
