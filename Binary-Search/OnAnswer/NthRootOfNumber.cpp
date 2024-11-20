#include <iostream>
#include <vector>
using namespace std;

int func(int mid, int n, int m) {
    long long ans = 1;

    for (int i = 1; i <= n; i++) {
        ans *= mid;
        if (ans > m)  // if ans > m, then mid is greater than the nth root of m
            return 2;
    }
    if (ans == m)  // if ans == m, then mid is the nth root of m
        return 1;
    else
        return 0;  // if ans < m, then mid is less than the nth root of m
}

int optimal(int n, int m) {
    int low = 1;
    int high = m;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int val = func(mid, n, m);

        if (val == 1)  // if ans == m, then mid is the nth root of m
            return mid;
        else if (val ==
                 2)  // if ans > m, then mid is greater than the nth root of m
            high = mid - 1;
        else
            low =
                mid + 1;  // if ans < m, then mid is less than the nth root of m
    }
    return -1;
}

int main() {
    int n = 4, m = 65;
    cout << optimal(n, m) << endl;  // 3
}