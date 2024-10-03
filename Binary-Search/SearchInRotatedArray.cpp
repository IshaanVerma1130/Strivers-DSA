#include <bits/stdc++.h>
using namespace std;

int optimal(vector<int> arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] == arr[low] && arr[mid] == arr[high]) {
            low++;
            high--;
            continue;
        }

        if (arr[mid] >= arr[low]) {
            if (target <= arr[mid] && target >= arr[low]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else if (arr[mid] <= arr[high]) {
            if (target <= arr[high] && target >= arr[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 0, 0, 0, 0, 0, 1, 2, 3};
    int target = 0;
    cout << (optimal(arr, target) != -1) << endl;
    return 0;
}