#include <bits/stdc++.h>
using namespace std;

bool solve(string &str, int i) {
    if (i >= str.size() / 2) {
        return true;
    }
    if (str[i] != str[str.size() - 1 - i])
        return false;
    return solve(str, i + 1);
}

int main() {
    string str = "aabbccbbaa";
    cout << solve(str, 0);
    return 0;
}