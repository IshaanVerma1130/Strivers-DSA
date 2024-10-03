#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {7, 1, 5, 3, 6, 4};
    int minEl = INT_MAX;
    int maxPro = 0;

    for (auto i : arr) {
        minEl = min(minEl, i);
        maxPro = max(maxPro, i - minEl);
    }

    cout << maxPro;
}