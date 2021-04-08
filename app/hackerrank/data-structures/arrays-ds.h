// https://www.hackerrank.com/challenges/arrays-ds/problem

// Complete the reverseArray function below.
vector<int> reverseArray(vector<int> a) {
    /*
    // first solution

        size_t n = a.size();

        for (size_t i = 0; i < n / 2; ++i) {
            swap(a[i], a[n - i - 1]);
        }
    */

    // second solution
    std::reverse(begin(a), end(a));

    return a;
}