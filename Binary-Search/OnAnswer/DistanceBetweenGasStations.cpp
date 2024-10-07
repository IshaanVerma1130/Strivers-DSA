#include <bits/stdc++.h>
using namespace std;

long double brute(vector<int> arr, int k) {
    int howMany[arr.size() - 1] = {0};
    for (int gasStation = 1; gasStation <= k; gasStation++) {
        long double maxDistance = -1;
        int maxIndex = -1;

        for (int i = 0; i < arr.size() - 1; i++) {
            long double diff = arr[i + 1] - arr[i];
            long double sectionLength = diff / (howMany[i] + 1);
            if (maxDistance < sectionLength) {
                maxDistance = sectionLength;
                maxIndex = i;
            }
        }
        howMany[maxIndex] += 1;
    }

    long double maxLen = -1;
    for (int i = 0; i < arr.size() - 1; i++) {
        long double diff = arr[i + 1] - arr[i];
        long double sectionLength = diff / (howMany[i] + 1);
        maxLen = max(maxLen, sectionLength);
    }
    return maxLen;
}

long double better(vector<int> arr, int k) {
    priority_queue<pair<long double, int>> pq;
    for (int i = 0; i < arr.size() - 1; i++) {
        pq.push({arr[i + 1] - arr[i], i});
    }
    int howMany[arr.size() - 1] = {0};

    for (int gasStation = 0; gasStation < k; gasStation++) {
        auto tp = pq.top();
        pq.pop();
        int secitonIndex = tp.second;
        howMany[secitonIndex] += 1;
        long double diff = arr[secitonIndex + 1] - arr[secitonIndex];
        long double newSection = diff / (long double)(howMany[secitonIndex] + 1);
        pq.push({newSection, secitonIndex});
    }

    return pq.top().first;
}

int fun(vector<int> arr, long double sectionlength) {
    int gasStations = 0;
    for (int i = 0; i < arr.size() - 1; i++) {
        long double diff = arr[i + 1] - arr[i];
        gasStations += ceil(diff / sectionlength) - 1;
    }
    return gasStations;
}

long double optimal(vector<int> arr, int k) {
    long double low = 0;
    long double high = INT_MIN;
    for (int i = 0; i < arr.size() - 1; i++) {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    long double ans = -1;
    while (high - low > 1e-6) {
        long double mid = low + (high - low) / 2;
        int gasStations = fun(arr, mid);
        if (gasStations > k) {
            low = mid;
        } else {
            ans = mid;
            high = mid;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    cout << brute(arr, k) << endl;
    cout << better(arr, k) << endl;
    cout << optimal(arr, k) << endl;
}