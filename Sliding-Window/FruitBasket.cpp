#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int optimalLess(vector<int> arr, int k) {
    unordered_map<int, int> freq;
    int maxFruit = 0;
    int i = 0;
    int j = 0;
    int n = arr.size();

    while (j < n) {
        freq[arr[j]]++;
        while (freq.size() > k) {
            freq[arr[i]]--;
            if (freq[arr[i]] == 0) {
                freq.erase(arr[i]);
            }
            i++;
        }
        if (freq.size() <= k) {
            maxFruit = max(maxFruit, j - i + 1);
        }
        j++;
    }
    return maxFruit;
}

int optimalBest(vector<int> arr, int k) {
    unordered_map<int, int> freq;
    int maxFruit = 0;
    int i = 0;
    int j = 0;
    int n = arr.size();

    while (j < n) {
        freq[arr[j]]++;
        if (freq.size() > k) {
            freq[arr[i]]--;
            if (freq[arr[i]] == 0) {
                freq.erase(arr[i]);
            }
            i++;
        }
        if (freq.size() <= k) {
            maxFruit = max(maxFruit, j - i + 1);
        }
        j++;
    }
    return maxFruit;
}

int main() {
    vector<int> arr = {1, 2, 1, 3, 4, 3, 2, 3, 2};
    int k = 2;
    cout << optimalLess(arr, k) << endl;
    cout << optimalBest(arr, k) << endl;
    return 0;
}