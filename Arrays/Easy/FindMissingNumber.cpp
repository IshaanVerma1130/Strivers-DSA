#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {0, 1, 2, 3, 4, 6, 7, 8, 9};
    int n = sizeof(arr) - sizeof(int);

    int total = (n * (n + 1)) / 2;
    int sum = 0;

    for (auto i : arr) {
        sum += i;
    }
    cout << total - sum;
}