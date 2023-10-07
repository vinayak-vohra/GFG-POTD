//{ Driver Code Starts
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

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends
/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}*head;
*/
class Solution
{
public:
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
};

//{ Driver Code Starts.

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int data;
        cin >> data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        map<Node *, int> mp;
        mp[head] = head->data;
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
            mp[tail] = tail->data;
        }
        struct Node *failure = new Node(-1);
        Solution ob;
        head = ob.pairWiseSwap(head);
        int flag = 0;
        struct Node *temp = head;
        while (temp)
        {
            if (mp[temp] != temp->data)
            {
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        if (flag)
            printList(failure);
        else
            printList(head);
    }
    return 0;
}

// } Driver Code Ends