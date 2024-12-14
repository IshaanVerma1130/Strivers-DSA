#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int optimal(vector<int> arr, int k) {
    int lsum = 0;
    int rsum = 0;
    int maxsum = 0;

    for (int i = 0; i < k; i++) {
        lsum += arr[i];
    }
    maxsum = lsum;

    int rIndex = arr.size() - 1;
    for (int i = k - 1; i >= 0; i--) {
        lsum -= arr[i];
        rsum += arr[rIndex];
        maxsum = max(maxsum, lsum + rsum);
        rIndex--;
    }

    return maxsum;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;
    cout << optimal(arr, k) << endl;
    return 0;
}