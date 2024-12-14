#include <iostream>
#include <vector>
using namespace std;

void insert(vector<int>& arr, int n, int x) {
    if (n == 0 || arr[n - 1] <= x) {
        arr.push_back(x);
        return;
    }

    int temp = arr[n - 1];
    arr.pop_back();
    insert(arr, n - 1, x);
    arr.push_back(temp);
}
void optimal(vector<int>& arr, int n) {
    if (n == 1) {
        return;
    }
    int temp = arr[n - 1];
    arr.pop_back();
    optimal(arr, n - 1);
    insert(arr, n - 1, temp);
}

int main() {
    vector<int> arr = {5, 1, 3, 2, 4};
    optimal(arr, arr.size());
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}