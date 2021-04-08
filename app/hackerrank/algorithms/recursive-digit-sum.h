// https://www.hackerrank.com/challenges/recursive-digit-sum/problem

// Complete the superDigit function below.

long sum_r(const string& n, size_t i) {
    long num = n[i] - '0'; // convert char to int

    if (i == 0) {
        return num;
    }

    return num + sum_r(n, --i);
}

int superDigit(string str, int k) {
    if (str.length() == 0) {
        return 0;
    }

    long sum = sum_r(str, str.length() - 1) * k;

    if (sum < 10) {
        return sum;
    }

    return superDigit(std::to_string(sum), 1);
}
