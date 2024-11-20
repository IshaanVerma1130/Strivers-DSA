#include <iostream>
#include <vector>#include <iostream>
#include <vector>using namespace std;

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
    return arr[high];
}

int main() {
    vector<int> arr = {3, 4, 4, 7, 8, 10};
    int target = 5;
    cout << optimal(arr, target) << endl;
    return 0;
}