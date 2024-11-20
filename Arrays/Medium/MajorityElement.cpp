#include <iostream>
#include <vector>
using namespace std;

int main() {
    int arr[] = {7, 7, 5, 7, 5, 1, 5, 7, 5, 5, 7, 7, 5, 5, 5, 5};

    int count = 0;
    int el;

    for (auto i : arr) {
        if (count == 0) {
            el = i;
            count = 1;
        } else if (i == el) {
            count++;
        } else {
            count--;
        }
    }

    count = 0;

    for (auto i : arr) {
        if (i == el) {
            count++;
        }
    }

    if (count >= (sizeof(arr) / sizeof(arr[0])) / 2)
        cout << el;
    else
        cout << -1;
}