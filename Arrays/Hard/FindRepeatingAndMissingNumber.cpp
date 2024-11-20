#include <iostream>
#include <vector>
using namespace std;

vector<int> brute(vector<int> arr) {
    int n = arr.size();
    int missing = -1;
    int repeating = -1;

    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == i) {
                count++;
            }
        }
        if (count == 0) missing = i;
        if (count == 2) repeating = i;
        if (repeating != -1 && missing != -1) {
            break;
        }
    }
    return {repeating, missing};
}

vector<int> better(vector<int> arr) {
    int n = arr.size();
    int missing = -1;
    int repeating = -1;

    int hash[n + 1] = {0};

    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }

    for (int i = 1; i <= n; i++) {
        if (hash[i] == 0)
            missing = i;
        else if (hash[i] == 2)
            repeating = i;
        if (repeating != -1 && missing != -1) {
            break;
        }
    }
    return {repeating, missing};
}

vector<int> optimal(vector<int> arr) {
    int n = arr.size();

    long long Sn = (n * (n + 1)) / 2;
    long long S2n = (n * (n + 1) * (2 * n + 1)) / 6;

    long long sum = 0;
    long long sumSq = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        sumSq += arr[i] * arr[i];
    }

    long long val1 = Sn - sum;
    long long val2 = S2n - sumSq;
    val2 = val2 / val1;

    int missing = (val1 + val2) / 2;
    int repeating = missing - val1;

    return {(int)repeating, (int)missing};
}

int main() {
    vector<int> arr = {4, 3, 6, 2, 1, 1};
    vector<int> res = brute(arr);

    cout << "Brute Force: " << endl;
    cout << "Repeating: " << res[0] << " Missing: " << res[1] << endl;

    res = better(arr);
    cout << "Better: " << endl;
    cout << "Repeating: " << res[0] << " Missing: " << res[1] << endl;

    res = optimal(arr);
    cout << "Optimal: " << endl;
    cout << "Repeating: " << res[0] << " Missing: " << res[1] << endl;

    return 0;
}