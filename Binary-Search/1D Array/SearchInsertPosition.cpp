#include <iostream>
#include <vector>
using namespace std;

int optimal(vector<int> &arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) return mid;
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int main() {
    vector<int> arr = {1, 2, 4, 7};
    int target = 2;
    cout << optimal(arr, target) << endl;
    return 0;
}