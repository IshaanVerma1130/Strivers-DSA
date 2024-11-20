#include <iostream>
#include <vector>
using namespace std;

int brute(vector<int> arr) {
    int count = 0;

    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] > arr[j]) {
                count++;
            }
        }
    }
    return count;
}
int merge(vector<int> &arr, int low, int mid, int high) {
    int count = 0;
    vector<int> temp;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            count += mid - left + 1;
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
    return count;
}
int mS(vector<int> &arr, int low, int high) {
    int count = 0;
    if (low >= high) return count;
    int mid = (low + high) / 2;
    count += mS(arr, low, mid);
    count += mS(arr, mid + 1, high);
    count += merge(arr, low, mid, high);
    return count;
}
int optimal(vector<int> arr, int n) { return mS(arr, 0, n - 1); }

int main() {
    vector<int> arr = {1, 20, 6, 4, 5};
    cout << brute(arr) << endl;
    arr = {1, 20, 6, 4, 5};
    cout << optimal(arr, arr.size()) << endl;
    return 0;
}