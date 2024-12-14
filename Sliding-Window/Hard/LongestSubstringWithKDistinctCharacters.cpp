#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int optimal(string s, int k) {
    int n = s.size();
    int i = 0, j = 0;
    int maxLen = 0;
    unordered_map<char, int> mp;

    while (j < n) {
        mp[s[j]]++;

        if (mp.size() > k) {
            mp[s[i]]--;
            if (mp[s[i]] == 0) {
                mp.erase(mp[s[i]]);
            }
            i++;
        }

        if (mp.size() <= k) maxLen = max(maxLen, j - i + 1);
        j++;
    }

    return maxLen;
}

int main() {
    string s = "aabacbebebe";
    int k = 3;
    cout << optimal(s, k) << endl;
    return 0;
}