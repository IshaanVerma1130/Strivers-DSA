#include <iostream>
#include <vector>
using namespace std;

int fun(vector<int> arr, int distance) {
    int cows = 1;
    int lastCow = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] - lastCow >= distance) {
            cows += 1;
            lastCow = arr[i];
        }
    }
    return cows;
}

int optimal(vector<int> arr, int cows) {
    sort(arr.begin(), arr.end());
    int low = 0;
    int high = arr[arr.size() - 1] - arr[0];
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int val = fun(arr, mid);

        if (val < cows) {
            high = mid - 1;
        } else {
            ans = mid;
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {4, 2, 1, 3, 6};
    int cows = 2;
    cout << optimal(arr, cows) << endl;
}
