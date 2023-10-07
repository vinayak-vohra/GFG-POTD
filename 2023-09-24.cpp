#include <bits/stdc++.h>
using std::vector;
using std::unordered_map;

vector<int> duplicates(int arr[], int n)
{
    // code here
    unordered_map<int, int> umap;
    vector<int> s;
    for (int i = 0; i < n; i++)
    {
        umap[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
        if (umap[i] > 1)
            s.push_back(i);

    if (!s.size())
        s.push_back(-1);

    return s;
}