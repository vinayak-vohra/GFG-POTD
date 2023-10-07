#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *pairWiseSwap(struct Node *head)
{
    if (!head || !head->next)
        return head;

    Node *even = head->next; // save even node
    Node *odd = head;        // save odd node
    Node *base = even;       // save new head
    Node *save = nullptr;
    // 1 2 3 4 5 6 7 8
    // 2->1->3->4

    while (1)
    {
        odd->next = even->next;
        even->next = odd;

        if (save)
            save->next = even;

        save = odd;

        odd = odd->next;

        if (!odd || !odd->next) //
            break;

        even = odd->next;
    }
    return base;
}
