//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/* A linked list node */

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

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void insert()
{
    int n, value;
    cin >> n;
    struct Node *temp;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        if (i == 0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}

// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element
  Node is defined as
  struct Node
  {
      int data;
      struct Node *next;

      Node(int x){
        data = x;
        next = NULL;
      }

   };

*/
class Solution
{
public:
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
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends