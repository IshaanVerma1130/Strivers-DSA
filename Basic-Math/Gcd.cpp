#include <iostream>
#include <vector>
using namespace std;

int gdc(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }

        if (a == 0)
            return b;
        else if (b == 0)
            return a;
    }
}

int main() {
    int a = 64;
    int b = 48;

    cout << gcd(a, b);
}
