#include <vector>
#include <iostream>
using namespace std;

vector<int> Union(vector<int> a, vector<int> b) {
    int n1 = a.size();
    int n2 = b.size();
    vector<int> ans;
    int i = 0;
    int j = 0;

    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            if (ans.size() == 0 || ans.back() != a[i])
                ans.push_back(a[i]);
            i++;
        } else if (b[j] < a[i]) {
            if (ans.size() == 0 || ans.back() != b[j])
                ans.push_back(b[j]);
            j++;
        }
    }

    while (i < n1) {
        if (ans.size() == 0 || ans.back() != a[i])
            ans.push_back(a[i]);
        i++;
    }

    while (j < n2) {
        if (ans.size() == 0 || ans.back() != b[j])
            ans.push_back(b[j]);
        j++;
    }

    return ans;
}

vector<int> Intersection(vector<int> a, vector<int> b) {
    int n1 = a.size();
    int n2 = b.size();
    vector<int> ans;
    int i = 0;
    int j = 0;

    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            i++;
        } else if (a[i] > b[j]) {
            j++;
        } else {
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main() {
    vector<int> arr1 = {1, 1, 2, 4, 5};
    vector<int> arr2 = {1, 2, 3, 4, 4, 6};

    vector<int> ansU = Union(arr1, arr2);
    vector<int> ansI = Intersection(arr1, arr2);

    for (auto i : ansU) {
        cout << i << " ";
    }
    cout << "\n";
    for (auto i : ansI) {
        cout << i << " ";
    }
}