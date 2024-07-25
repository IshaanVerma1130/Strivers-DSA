#include <bits/stdc++.h>
using namespace std;

vector<int> solveForEqualPosNeg(vector<int> arr)
{ // Optimal Approach
    vector<int> ans(arr.size(), 0);
    int posI = 0;
    int negI = 1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] >= 0)
        {
            ans[posI] = arr[i];
            posI += 2;
        }
        else
        {
            ans[negI] = arr[i];
            negI += 2;
        }
    }

    return ans;
}

vector<int> solveForUnequalPosNeg(vector<int> arr)
{ // Brute Force
    vector<int> pos;
    vector<int> neg;
    vector<int> ans(arr.size(), 0);

    for (auto i : arr)
    {
        if (i >= 0)
        {
            pos.push_back(i);
        }
        else
        {
            neg.push_back(i);
        }
    }

    if (pos.size() > neg.size())
    {
        for (int i = 0; i < neg.size(); i++)
        {
            ans[2 * i] = pos[i];
            ans[2 * i + 1] = neg[i];
        }

        int index = neg.size() * 2;
        for (int i = neg.size(); i < pos.size(); i++)
        {
            ans[index] = pos[i];
            index++;
        }
    }
    else
    {
        for (int i = 0; i < pos.size(); i++)
        {
            ans[2 * i] = pos[i];
            ans[2 * i + 1] = neg[i];
        }

        int index = pos.size() * 2;
        for (int i = pos.size(); i < neg.size(); i++)
        {
            ans[index] = neg[i];
            index++;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr1 = {3, 1, -2, -5, 2, -4};
    vector<int> arr2 = {3, 1, -2, -5, 2, -4, -6, -7};

    vector<int> equal = solveForEqualPosNeg(arr1);
    vector<int> unequal = solveForUnequalPosNeg(arr2);

    cout << "Equal:\n";
    for (auto i : equal)
    {
        cout << i << " ";
    }

    cout << "\nUnequal:\n";
    for (auto i : unequal)
    {
        cout << i << " ";
    }
}