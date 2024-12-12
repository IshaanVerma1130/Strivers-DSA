#include <iostream>
using namespace std;

int optimal(string s) {
    int n = s.size();
    int ans = 0;
    int i = 0, j = 0;
    int freq[256] = {-1};

    while (j < n) {
        if (freq[s[j]] != -1) {
            if (freq[s[j]] >= i) {
                i = freq[s[j]] + 1;
            }
        }
        int len = j - i + 1;
        ans = max(ans, len);
        freq[s[j]] = j;
        j++;
    }

    return ans;
}

int main() {
    string s = "abcabcbb";
    cout << optimal(s) << endl;
    return 0;
}