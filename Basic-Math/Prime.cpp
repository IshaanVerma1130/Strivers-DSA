#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 57;
    int count = 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            count++;
            if (n / i != i) {
                count++;
            }
        }
    }
    if (count == 2)
        cout << "Prime";
    else
        cout << "Not Prime";
}