#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 7, 7, 8, 8};
    int xorV = 0;

    for (auto i : arr) {
        xorV ^= i;
    }

    cout << xorV << endl;
}