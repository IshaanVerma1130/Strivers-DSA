#include <iostream>
#include <vector>
using namespace std;
// Same as painters partioning
int fun(vector<int> arr, int pages) {
    int students = 1;
    int sum = 0;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if (sum > pages) {
            students += 1;
            sum = arr[i];
        }
    }

    return students;
}
int optimal(vector<int> arr, int students) {
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int val = fun(arr, mid);

        if (val > students) {
            low = mid + 1;
        } else {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {7, 2, 5, 10, 8};
    int students = 2;
    cout << optimal(arr, students) << endl;
}