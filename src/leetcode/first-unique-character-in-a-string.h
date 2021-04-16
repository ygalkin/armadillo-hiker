// https://leetcode.com/problems/first-unique-character-in-a-string/

class Solution {
public:
    static constexpr size_t _english_alphabet_letters_num = 'z' - 'a' + 1;
    static constexpr size_t _MAX = numeric_limits<size_t>::max();

    int firstUniqChar(string s) {
        // <first index of char in a string, frequency of a char>, 26
        std::array<pair<size_t, size_t>, _english_alphabet_letters_num> lookup_tbl{ pair(0, 0) };

        // fill the lookup table
        for (int i = s.size() - 1; i >= 0; --i) {
            auto& item = lookup_tbl[s[i] - 'a'];
            item.first = i;
            item.second += 1;
        }

        auto index{ _MAX };
        for (auto i = 0; i < lookup_tbl.size(); ++i) {
            const auto item = lookup_tbl[i];
            if (item.second == 1 && item.first < index) {
                index = item.first;
            }
        }

        return index == _MAX ? -1 : index;
    }
};
