#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr) {
    int low = 0;
    int mid = 0;
    int high = sizeof(arr) / sizeof(arr[0]) - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else {
            swap(arr[high], arr[mid]);
            high--;
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 0};

    solve(arr);

    for (auto i : arr) {
        cout << i << " ";
    }
}