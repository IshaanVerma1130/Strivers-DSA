#include <iostream>
#include <vector>
using namespace std;

void insert(vector<int>& arr, int temp) {
    if (arr.size() == 0) {
        arr.push_back(temp);
        return;
    }

    int val = arr.back();
    arr.pop_back();
    insert(arr, temp);
    arr.push_back(val);
}
void optimal(vector<int>& arr) {
    if (arr.size() == 0 || arr.size() == 1) {
        return;
    }

    int temp = arr.back();
    arr.pop_back();
    optimal(arr);
    insert(arr, temp);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    optimal(arr);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}