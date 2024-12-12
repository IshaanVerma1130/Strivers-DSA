#include <iostream>
#include <string>
#include <vector>
using namespace std;

int optimal(string s) {
    int n = s.size();
    vector<int> index(3, -1);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        index[s[i] - 'a'] = i;
        if (index[0] != -1 && index[1] != -1 && index[2] != -1) {
            ans += min(index[0], min(index[1], index[2])) + 1;
        }
    }

    return ans;
}

int main() {
    string s = "abcabc";
    cout << optimal(s) << endl;
    return 0;
}