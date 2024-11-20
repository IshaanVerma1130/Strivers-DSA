#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int> &arr, int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int n = arr.size();
    int k = 21;

    k = k % n;
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;
    reverse(arr, 0, n - k - 1);
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;
    // reverse(arr + k, arr + n);
    // for (auto i : arr) {
    //     cout << i << " ";
    // }
    // cout << endl;
    // reverse(arr, arr + n);

    // for (auto i : arr) {
    //     cout << i << " ";
    // }
}