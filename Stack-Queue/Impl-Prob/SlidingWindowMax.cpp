#include <bits/stdc++.h>
using namespace std;

vector<int> optimal(vector<int> arr, int k) {
    deque<int> dq;
    vector<int> maxi;
    int n = arr.size();
    int i = 0;
    int j = 0;

    while (j < n) {
        while (!dq.empty() && dq.front() < i) {
            dq.pop_front();
        }
        if (i <= dq.front() && dq.front() <= j) {
            if (!dq.empty()) {
                maxi.push_back(dq.front());
            }
        }
    }
}