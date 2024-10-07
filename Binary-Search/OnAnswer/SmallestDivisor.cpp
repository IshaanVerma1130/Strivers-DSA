#include <bits/stdc++.h>
using namespace std;

int fun(vector<int> arr, int divisor) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += ceil((double)arr[i] / divisor);
    }
    return sum;
}

int optimal(vector<int> arr, int threshold) {
    int low = 1;
    int high = *max_element(arr.begin(), arr.end());
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int val = fun(arr, mid);

        if (val <= threshold) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {21212, 10101, 12121};
    int threshold = 1000000;
    cout << optimal(arr, threshold) << endl;
}