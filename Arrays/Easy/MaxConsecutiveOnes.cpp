#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1, 1, 0, 1, 1, 1, 0, 1, 1};

    int count = 0;
    int maxOne = 0;

    for (auto i : arr) {
        if (i == 1) {
            count++;
            maxOne = max(maxOne, count);
        } else
            count = 0;
    }

    cout << maxOne;
}