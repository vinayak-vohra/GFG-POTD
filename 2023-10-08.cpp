struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

Node *sortedInsert(struct Node *head, int data)
{
    // create new node
    Node *newNode = new Node(data);

    // null check
    if (!head)
        return newNode;

    // update head
    else if (head->data >= newNode->data)
    {
        newNode->next = head;
        head = newNode;
    }

    // find insert position
    else
    {
        Node *save; // to save previous
        Node *temp = head;

        while (temp && (newNode->data > temp->data))
        {
            save = temp;
            temp = temp->next;
        }

        newNode->next = temp;
        save->next = newNode;
    }
    return head;
}

// 25->36->47->58->69->80