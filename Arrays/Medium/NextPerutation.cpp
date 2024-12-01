#include <iostream>
#include <vector>
using namespace std;

// Better solution is using next_permutation in cpp STL which is also the one
// below

// from the end of the array
// find array index i such that arr[i] < arr[i+1]
// find array index j such that arr[j] > arr[i]
// swap arr[i] and arr[j]
// reverse the array from i+1 to end
vector<int> optimal(vector<int> arr) {
    int n = arr.size();
    int index = -1;
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        reverse(arr.begin(), arr.end());
        return arr;
    }

    for (int i = n - 1; i > index; i--) {
        if (arr[i] > arr[index]) {
            swap(arr[i], arr[index]);
            break;
        }
    }
    reverse(arr.begin() + index + 1, arr.end());
    return arr;
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> res = optimal(arr);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}