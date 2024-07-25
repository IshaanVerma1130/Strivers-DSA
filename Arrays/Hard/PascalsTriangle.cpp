#include <bits/stdc++.h>
using namespace std;

long long nCr(int n, int r)
{
    long long res = 1;

    for (int i = 0; i < r; i++)
    {
        res *= n - i;
        res /= i + 1;
    }

    return res;
}

long long valueAtRandC(int r, int c) // Formula based
{
    return nCr(r - 1, c - 1);
}

void printRowBrute(int r)
{
    for (int i = 1; i <= r; i++)
    {
        cout << valueAtRandC(r, i) << " ";
    }
}

void printRowOptimal(int r)
{
    long long ans = 1;
    cout << 1 << " ";

    for (int i = 1; i < r; i++)
    {
        ans *= r - i;
        ans /= i;
        cout << ans << " ";
    }
}

void printTriangle(int r)
{
    for (int i = 1; i <= r; i++)
    {
        printRowOptimal(i);
        cout << endl;
    }
}

int main()
{
    int r = 5;
    int c = 4;

    cout << "Value at R and C: " << valueAtRandC(r, c) << endl;
    cout << "Rth row (Brute): ";
    printRowBrute(r);
    cout << endl;
    cout << "Rth row (Optimal): ";
    printRowOptimal(r);
    cout << endl;
    cout << "Print triangle with " << r << " rows:\n";
    printTriangle(r);
}