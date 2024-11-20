#include <iostream>
#include <vector>
using namespace std;

int optimal(vector<int> arr, int target) {
    int n = arr.size();
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        // check for sorted half first as then we can compare if target lies in
        // that range
        if (arr[mid] >= arr[0]) {
            if (target <= arr[mid] && target >= arr[low]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            if (arr[mid] <= target && target <= arr[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    cout << optimal(arr, target) << endl;
}