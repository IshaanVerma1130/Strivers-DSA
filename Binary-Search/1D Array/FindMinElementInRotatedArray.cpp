#include <iostream>
#include <vector>
using namespace std;

// no duplicates
int aditya_verma(vector<int> arr) {
    int low = 0;
    int high = arr.size() - 1;

    if (arr[low] <= arr[high]) {
        return low;
    }

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int prev = (mid - 1 + arr.size()) % arr.size();
        int next = (mid + 1) % arr.size();

        if (arr[mid] < arr[prev] && arr[mid] < arr[next]) {
            return arr[mid];
        }

        if (arr[0] <= arr[mid]) {
            low = mid + 1;
        } else if (arr[mid] <= arr[arr.size() - 1]) {
            high = mid - 1;
        }
    }
    return -1;
}

int optimal(vector<int> arr) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = INT_MAX;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[low] <= arr[high]) {
            ans = min(ans, arr[low]);
            break;
        }

        if (arr[0] <= arr[mid]) {
            ans = min(ans, arr[low]);
            low = mid + 1;
        } else {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 100, 1, 2};
    cout << optimal(arr) << endl;
    return 0;
}