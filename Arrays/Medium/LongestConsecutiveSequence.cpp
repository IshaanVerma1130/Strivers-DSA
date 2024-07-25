#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int> &arr, int x)
{
    for (auto i : arr)
    {
        if (i == x)
            return true;
    }
    return false;
}

int brute(vector<int>(&arr))
{
    int longest = 1;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int count = 1;
        int x = arr[i];

        while (linearSearch(arr, x + 1))
        {
            x++;
            count++;
        }

        longest = max(longest, count);
    }
    return longest;
}

int better(vector<int>(&arr))
{
    int n = arr.size();
    if (n == 0)
        return 0;

    sort(arr.begin(), arr.end());

    int lastSmaller = INT_MIN;
    int count = 0;
    int longest = 1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] - 1 == lastSmaller)
        {
            count++;
            lastSmaller = arr[i];
        }
        else if (arr[i] != lastSmaller)
        {
            count = 1;
            lastSmaller = arr[i];
        }
        longest = max(longest, count);
    }

    return longest;
}

int optimal(vector<int>(&arr))
{
    int n = arr.size();
    if (n == 0)
        return 0;

    unordered_set<int> st;
    int longest = 1;

    for (auto i : arr)
    {
        st.insert(i);
    }

    for (auto i : st)
    {
        if (st.find(i - 1) == st.end())
        {
            int count = 1;
            int x = i;

            while (st.find(x + 1) != st.end())
            {
                x++;
                count++;
            }
            longest = max(longest, count);
        }
    }
    return longest;
}

int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4};

    cout << "Brute:" << brute(a) << "\n";
    cout << "Better:" << better(a) << "\n";
    cout << "Optimal:" << optimal(a) << "\n";
}