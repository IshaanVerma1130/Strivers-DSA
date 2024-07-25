#include <bits/stdc++.h>
using namespace std;

void solve(int arr[], int i, int n) {
    if (i >= n / 2) {
        return;
    }
    swap(arr[i], arr[n - 1 - i]);
    solve(arr, i + 1, n);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    solve(arr, 0, size(arr));
    for (int i : arr) {
        cout << i << " ";
    }
}