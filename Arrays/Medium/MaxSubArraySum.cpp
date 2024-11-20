#include <iostream>
#include <vector>
using namespace std;

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    long long sum = 0;
    long long maxi = LONG_MIN;
    int start = 0;
    int ansStart = 0, ansEnd = 0;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        if (sum == 0) {
            start = i;
        }
        sum += arr[i];
        if (sum > maxi) {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if (sum < 0) {
            sum = 0;
        }
    }
    if (maxi < 0) {
        maxi = 0;
    }
    cout << maxi << endl;
    cout << "Start: " << ansStart << endl;
    cout << "End: " << ansEnd << endl;
}