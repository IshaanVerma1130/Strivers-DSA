#include <iostream>
#include <vector>
using namespace std;

int lessThanOrEqual(vector<int> arr, int k) {
    int n = arr.size();
    int i = 0;
    int j = 0;
    int count = 0;
    int sum = 0;

    while (j < n) {
        sum += arr[j] % 2;
        while (sum > k) {
            sum -= arr[i] % 2;
            i++;
        }
        count += j - i + 1;
        j++;
    }
    return count;
}
int optimal(vector<int> arr, int k) {
    return lessThanOrEqual(arr, k) - lessThanOrEqual(arr, k - 1);
}

int main() {
    vector<int> arr = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    int k = 2;
    cout << optimal(arr, k) << endl;
    return 0;
}