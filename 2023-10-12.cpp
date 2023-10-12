#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};

unordered_map<string, int> dp;
string infix(Node *root)
{
    if (!root)
        return "N";

    string s = to_string(root->data) + infix(root->left) + infix(root->right);
    dp[s]++;
    cout << s << "\n";
    return s;
}

int dupSub(Node *root)
{
    infix(root);
    for (auto x : dp)
        if (x.second > 1 &&         // duplicate sub-tree
            x.first.size() / 2 > 2) // height > 1 (exclude N)
            return 1;

    return 0;
}