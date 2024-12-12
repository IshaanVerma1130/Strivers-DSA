#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int brute(string s, int k) {
    int n = s.size();
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        vector<int> freq(26, 0);
        int maxFreq = 0;
        for (int j = i; j < n; j++) {
            freq[s[j] - 'A']++;
            maxFreq = max(maxFreq, freq[s[j] - 'A']);
            int changes = j - i + 1 - maxFreq;
            if (changes <= k) {
                maxLen = max(maxLen, j - i + 1);
            } else {
                break;
            }
        }
    }
    return maxLen;
}

int better(string s, int k) {
    int n = s.size();
    int maxLen = 0;
    int maxFreq = 0;
    int i = 0;
    int j = 0;
    vector<int> freq(26, 0);

    while (j < n) {
        freq[s[j] - 'A']++;
        maxFreq = max(maxFreq, freq[s[j] - 'A']);

        while (j - i + 1 - maxFreq > k) {
            freq[s[i] - 'A']--;
            maxFreq = 0;
            for (int it = 0; it < 26; it++) {
                maxFreq = max(maxFreq, freq[it]);
            }
            i++;
        }

        if (j - i + 1 - maxFreq <= k) {
            maxLen = max(maxLen, j - i + 1);
        }
        j++;
    }

    return maxLen;
}

int optimal(string s, int k) {
    int n = s.size();
    int maxLen = 0;
    int maxFreq = 0;
    int i = 0;
    int j = 0;
    vector<int> freq(26, 0);

    while (j < n) {
        freq[s[j] - 'A']++;
        maxFreq = max(maxFreq, freq[s[j] - 'A']);

        if (j - i + 1 - maxFreq > k) {
            freq[s[i] - 'A']--;
            i++;
        }

        else if (j - i + 1 - maxFreq <= k) {
            maxLen = max(maxLen, j - i + 1);
        }
        j++;
    }

    return maxLen;
}

int main() {
    string s = "AABABBA";
    int k = 2;
    cout << brute(s, k) << endl;
    cout << better(s, k) << endl;
    return 0;
}