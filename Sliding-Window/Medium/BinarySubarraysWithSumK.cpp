#include <iostream>
#include <vector>
using namespace std;

int lessThanEqual(vector<int> arr, int k) {
    if (k < 0) return 0;

    int n = arr.size();
    int count = 0;
    int sum = 0;
    int i = 0;
    int j = 0;

    while (j < n) {
        sum += arr[j];
        while (sum > k) {
            sum -= arr[i];
            i++;
        }
        count += j - i + 1;
        j++;
    }
    return count;
}

int optimal(vector<int> arr, int k) {
    return lessThanEqual(arr, k) - lessThanEqual(arr, k - 1);
}

int main() {
    vector<int> arr = {1, 0, 1, 0, 1};
    int k = 2;
    cout << optimal(arr, k) << endl;
    return 0;
}