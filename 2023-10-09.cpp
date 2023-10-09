#include <bits/stdc++.h>
using std::max;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

int height(struct Node *node, int depth = 0)
{
    // No Node
    if (!node)
        return depth;

    // return max of left and right
    return max(
               height(node->left, depth),
               height(node->right, depth)) +
           1;
}