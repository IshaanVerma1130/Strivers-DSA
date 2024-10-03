#include <bits/stdc++.h>
using namespace std;

int first(vector<int> arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            ans = mid;
            high = mid - 1;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int last(vector<int> arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            ans = mid;
            low = mid + 1;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int optimal(vector<int> arr, int target) {
    int firstOccurence = first(arr, target);
    int lastOccurence = last(arr, target);

    if (firstOccurence == -1)
        return 0;
    return lastOccurence - firstOccurence + 1;
}

int main() {
    vector<int> arr = {4, 4, 4, 7, 8, 10};
    int target = 4;
    cout << optimal(arr, target) << endl;
    return 0;
}
