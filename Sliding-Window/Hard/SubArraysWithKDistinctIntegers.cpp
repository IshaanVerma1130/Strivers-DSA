#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int lessThanEqual(vector<int> arr, int k) {
    int i = 0;
    int j = 0;
    int count = 0;
    unordered_map<int, int> mp;

    while (j < arr.size()) {
        mp[arr[j]]++;

        while (mp.size() > k) {
            mp[arr[i]]--;
            if (mp[arr[i]] == 0) {
                mp.erase(arr[i]);
            }
            i++;
        }

        if (mp.size() <= k) {
            count += j - i;
        }
        j++;
    }

    return count;
}

int optimal(vector<int> arr, int k) {
    return lessThanEqual(arr, k) - lessThanEqual(arr, k - 1);
}

int main() {
    vector<int> arr = {2, 1, 2, 1, 6};
    int k = 2;

    cout << optimal(arr, k) << endl;

    return 0;
}