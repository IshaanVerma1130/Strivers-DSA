#include <bits/stdc++.h>
using namespace std;

int optimal(vector<int> arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX, index = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[low] <= arr[high]) {
            if (ans > arr[low]) {
                ans = arr[low];
                index = low;
            }
            break;
        }

        if (arr[0] < arr[mid]) {
            if (ans > arr[low]) {
                ans = arr[low];
                index = low;
            }
            low = mid + 1;
        } else {
            if (ans > arr[mid]) {
                ans = arr[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }

    return index;
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    cout << optimal(arr) << endl;
}