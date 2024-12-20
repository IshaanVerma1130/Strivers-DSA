#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
using namespace std;

string optimal(string s, string t) {
    vector<int> mp(256, 0);
    for (auto c : t) mp[c]++;
    int i = 0;
    int j = 0;
    int count = 0;
    int minLen = INT_MAX;
    int start = -1;

    while (j < s.size()) {
        if (mp[s[j]] > 0) {
            count++;
        }

        mp[s[j]]--;

        while (count == t.size()) {
            if (minLen > j - i + 1) {
                minLen = j - i + 1;
                start = i;
            }
            mp[s[i]]++;
            if (mp[s[i]] > 0) {
                count--;
            }
            i++;
        }
        j++;
    }
    return (start == -1) ? "" : s.substr(start, minLen);
}

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << optimal(s, t) << endl;
    return 0;
}