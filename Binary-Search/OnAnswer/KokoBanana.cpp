#include <iostream>
#include <vector>
using namespace std;

int fun(vector<int> arr, int mid) {
    int val = 0;
    for (int i = 0; i < arr.size(); i++) {
        val += ceil((double)arr[i] / mid);
    }
    return val;
}

int optimal(vector<int> arr, int h) {
    int low = 1, high = *max_element(arr.begin(), arr.end());
    int ans = INT_MAX;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int val = fun(arr, mid);

        if (val <= h) {
            ans = min(ans, mid);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {3, 6, 7, 11};
    int h = 8;
    cout << optimal(arr, h) << endl;  // 4
}