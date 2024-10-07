#include <bits/stdc++.h>
using namespace std;

int fun(vector<int> arr, int capacity) {
    int days = 0;
    int sum = 0;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if (sum > capacity) {
            days += 1;
            sum = arr[i];
        }
    }

    return days + 1;
}

int optimal(vector<int> arr, int days) {
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int val = fun(arr, mid);
        if (val <= days) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
int main() {
    vector<int> arr = {5, 4, 5, 2, 3, 4, 5, 6};
    int days = 5;
    cout << optimal(arr, days) << endl;
}