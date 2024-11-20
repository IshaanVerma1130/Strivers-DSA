#include <iostream>
#include <vector>
using namespace std;

// Brute: Generate all subarrays and check if XOR is equal to k O(n^3)
// Better: Generate XOR as you go and check if XOR is equal to k O(n^2)

int optimal(vector<int> arr, int k) {
    unordered_map<int, int> mp;
    int n = arr.size();
    int xorSum = 0;
    int count = 0;

    mp[0] = 1;

    for (int i = 0; i < n; i++) {
        xorSum ^= arr[i];

        int x = xorSum ^ k;

        if (mp.find(x) != mp.end()) {  //
            count += mp[x];  // Could also be written as just count += mp[x];
        }  //
        mp[xorSum]++;
    }

    return count;
}

int main() {
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    cout << optimal(arr, k) << endl;
    return 0;
}