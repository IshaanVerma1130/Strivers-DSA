#include <bits/stdc++.h>
using namespace std;

bool solve(int n) {
    int copy = n;
    int len_n = to_string(n).length();
    int sum = 0;

    while (n > 0) {
        int i = n % 10;
        sum += pow(i, len_n);
        n /= 10;
    }

    if (sum == copy) {
        return true;
    }
    return false;
}

int main() {
    int n = 153;
    cout << solve(n);
}