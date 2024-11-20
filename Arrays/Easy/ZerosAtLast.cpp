#include <iostream>
#include <vector>
using namespace std;

int main() {
    int arr[] = {1, 2, 0, 3, 4, 0, 0, 5, 6, 0, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int j = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            j = i;
            break;
        }
    }

    for (int i = j + 1; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[j], arr[i]);
            j++;
        }
    }

    for (auto i : arr) {
        cout << i << " ";
    }
}