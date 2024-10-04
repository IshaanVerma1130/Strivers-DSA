#include <bits/stdc++.h>
using namespace std;

int optimal(vector<int> arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int ind = high + 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= target) {
            low = mid + 1;
        } else {
            ind = mid;
            high = mid - 1;
        }
    }

    return ind;
}

int main() {
    vector<int> arr = {3, 5, 8, 9, 15, 19};
    int target = 9;
    cout << optimal(arr, target) << endl;
}