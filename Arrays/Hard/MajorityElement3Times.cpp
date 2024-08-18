#include <bits/stdc++.h>
using namespace std;
vector<int> brute(vector<int> arr) {
    vector<int> ls;

    for (int i = 0; i < arr.size(); i++) { // O(n^2)
        if (ls.size() == 0 || ls[0] != arr[i]) {
            int count = 0;
            for (int j = 0; j < arr.size(); j++) {
                if (arr[j] == arr[i]) {
                    count++;
                }
            }
            if (count == (arr.size() / 3 + 1)) {
                ls.push_back(arr[i]);
                if (ls.size() == 2) {
                    break;
                }
            }
        }
    }

    return ls;
}

vector<int> better(vector<int> arr) { // O(n) * O(1) in best case unordered map
    unordered_map<int, int> mp;
    vector<int> ls;
    for (int i = 0; i < arr.size(); i++) {
        mp[arr[i]]++;
        if (mp[arr[i]] == (arr.size() / 3 + 1)) {
            ls.push_back(arr[i]);
            if (ls.size() == 2) {
                break;
            }
        }
    }

    return ls;
}

vector<int> optimal(vector<int> arr) {
    int count1 = 0, count2 = 0;
    int el1, el2;

    for (int i = 0; i < arr.size(); i++) {
        if (count1 == 0 && el2 != arr[i]) {
            count1 = 1;
            el1 = arr[i];
        } else if (count2 == 0 && el1 != arr[i]) {
            count2 = 0;
            el2 = arr[i];
        } else if (el1 == arr[i]) {
            count1++;
        } else if (el2 == arr[i]) {
            count2++;
        } else {
            count1--;
            count2--;
        }
    }

    vector<int> ls;
    count1 = 0;
    count2 = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == el1) {
            count1++;
        } else if (arr[i] == el2) {
            count2++;
        }
    }
    if (count1 > arr.size() / 3) {
        ls.push_back(el1);
    }
    if (count2 > arr.size() / 3) {
        ls.push_back(el2);
    }
    return ls;
}

int main() {
    vector<int> arr = {1, 1, 1, 2, 2, 3, 3, 3};

    vector<int> bruteAns = brute(arr);
    cout << "Brute: ";
    for (int i = 0; i < bruteAns.size(); i++) {
        cout << bruteAns[i] << " ";
    }
    cout << endl;

    vector<int> betterAns = better(arr);
    cout << "Better: ";
    for (int i = 0; i < betterAns.size(); i++) {
        cout << betterAns[i] << " ";
    }
    cout << endl;

    vector<int> optimalAns = optimal(arr);
    cout << "Optimal: ";
    for (int i = 0; i < optimalAns.size(); i++) {
        cout << optimalAns[i] << " ";
    }
    cout << endl;
}