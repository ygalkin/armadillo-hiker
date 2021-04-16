
//https://www.hackerrank.com/challenges/lonely-integer/problem

// Complete the lonelyinteger function below.
// XOR solution
int lonelyinteger(vector<int> a) {
    auto n = 0;

    for (const auto& i : a) {
        n ^= i;
    }

    return n;
}