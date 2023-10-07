#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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

void rearrange(struct Node *odd)
{
    Node *save = nullptr; // save last node (tail)
    Node *temp = nullptr; // temporary head for odd values

    bool isAlt = false; // alternate node check

    // iterate over list
    while (odd)
    {
        // if alternate node
        if (isAlt)
        {
            // unlink from current list
            save->next = odd->next;

            // link to alternate list (temp)
            odd->next = temp; // this saves the alternate list in reverse order

            // update temp head
            temp = odd;

            // go to next
            odd = save->next;
        }
        else
        {
            // update save
            save = odd;

            // go to next
            odd = odd->next;
        }

        isAlt = !isAlt;
    }
    save->next = temp;
}
