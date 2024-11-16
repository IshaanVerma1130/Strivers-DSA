#include<bits/stdc++.h>
using namespace std;

int optimal(vector<int> arr) {
    int n = arr.size();
    if (n == 1) {
      return n;
    }
    int i = 0;
    for (int j = 1; j < n; j++) {
        if (arr[j] != arr[i]) {
            arr[i+1] = arr[j];  
            i++;
        }
    }
    return i+1;
}
