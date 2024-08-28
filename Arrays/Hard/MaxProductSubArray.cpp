#include <bits/stdc++.h>
using namespace std;

// Brute Force - 3 loops all subarrays O(n^3)
// Better - Kepp the result of multiplication of all elements till now and keep track of max and min O(n^2)

long long optimal(vector<int> arr) {
    long long maxProd = INT_MIN;

    long long prefixProd = 1;
    long long suffixProd = 1;

    for (int i = 0; i < arr.size(); i++) {
        prefixProd *= arr[i];
        suffixProd *= arr[arr.size() - i - 1];

        maxProd = max(maxProd, max(prefixProd, suffixProd));
        if (prefixProd == 0)
            prefixProd = 1;
        if (suffixProd == 0)
            suffixProd = 1;
    }
    return maxProd;
}

int main() {
    vector<int> nums = {1, 2, -3, 0, -4, -5};
    cout << "The maximum product subarray: " << optimal(nums) << endl;
    return 0;
}