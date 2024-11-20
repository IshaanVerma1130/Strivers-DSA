#include <iostream>
#include <vector>
using namespace std;

// brute - generate all subarrays and check if sum is 0 O(n^3)
// better - Kadane's algo for sum 0 O(n^2). Dont generate but take the sum as
// you go.

int optimal(vector<int> arr) {
    unordered_map<int, int> mp;
    int sum = 0, max_len = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if (sum == 0) {
            max_len = i + 1;
        } else {
            if (mp.find(sum) != mp.end()) {
                max_len = max(max_len, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }
    }
    return max_len;
}

int main() {
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
    cout << optimal(arr) << endl;
    return 0;
}