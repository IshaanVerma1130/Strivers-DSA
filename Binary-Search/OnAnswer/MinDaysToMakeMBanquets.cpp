#include <iostream>
#include <vector>
using namespace std;

int fun(vector<int> arr, int day, int adj) {
    int count = 0;
    int val = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] <= day)
            count++;
        else {
            val += count / adj;
            count = 0;
        }
    }
    val += count / adj;
    return val;
}

int optimal(vector<int> arr, int numB, int adj) {
    int n = arr.size();
    if (numB > n / adj) {
        return -1;
    }
    int low = *min_element(arr.begin(), arr.end()),
        high = *max_element(arr.begin(), arr.end());
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int val = fun(arr, mid, adj);

        if (val < numB) {
            low = mid + 1;
        } else {
            ans = min(ans, mid);
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int numB = 2, adj = 3;
    cout << optimal(arr, numB, adj) << endl;  // 3
}