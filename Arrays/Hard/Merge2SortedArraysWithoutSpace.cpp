#include <iostream>
#include <vector>
using namespace std;

void optimal1(vector<int> &arr1, vector<int> &arr2, int n,
              int m) {  // O(min(n, m) + nlogn + mlogm)
    int left = n - 1;
    int right = 0;

    while (left >= 0 && right < m) {
        if (arr1[left] > arr2[right]) {
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        } else {
            break;
        }
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}

void swap(vector<int> &arr1, vector<int> &arr2, int ind1, int ind2) {
    if (arr1[ind1] > arr2[ind2]) {
        swap(arr1[ind1], arr2[ind2]);
    }
}
void optimal2(vector<int> &arr1, vector<int> &arr2, int n,
              int m) {  // O(log(n+m)) x O(n+m)
    int len = n + m;
    int gap = (len / 2) + (len % 2);

    while (gap > 0) {
        int left = 0;
        int right = left + gap;
        while (right < len) {
            if (left < n && right >= n) {
                swap(arr1, arr2, left, right - n);
            } else if (left >= n) {
                swap(arr2, arr2, left - n, right - n);
            } else {
                swap(arr1, arr1, left, right);
            }
            left++;
            right++;
        }
        if (gap == 1) break;
        gap = (gap / 2) + (gap % 2);
    }
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7, 9};
    vector<int> arr2 = {2, 4, 6, 8, 10};
    int n = arr1.size();
    int m = arr2.size();

    optimal1(arr1, arr2, n, m);
    cout << "Merged Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    vector<int> arr3 = {1, 3, 5, 7, 9};
    vector<int> arr4 = {2, 4, 6, 8, 10};

    optimal2(arr3, arr4, n, m);
    cout << "Merged Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr3[i] << " ";
    }
    for (int i = 0; i < m; i++) {
        cout << arr4[i] << " ";
    }
    cout << endl;
}