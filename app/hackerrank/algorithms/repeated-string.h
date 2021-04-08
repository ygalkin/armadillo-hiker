// https://www.hackerrank.com/challenges/repeated-string/problem
long count_n(const string& s, size_t n, char ch)
{
    // n < s.length()
    auto sum{ 0 };

    for (size_t i = 0; i < n; ++i) {
        if (s[i] == ch) {
            ++sum;
        }
    }

    return sum;
}

long repeatedString(string s, long n) {

    if (s.length() > n) {
        return count_n(s, n, 'a');
    }

    auto quotient = n / s.length();
    auto reminder = n % s.length();
    auto n_full = count_n(s, s.length(), 'a') * quotient;
    auto n_reminder{ 0 };
    if (reminder > 0) {
        n_reminder = count_n(s, reminder, 'a');
    }

    return n_full + n_reminder;
}