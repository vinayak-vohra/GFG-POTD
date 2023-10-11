#include <cstdlib>
#include <iomanip>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int data, Node *left = nullptr, Node *right = nullptr)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

int height(Node *node)
{
    return node ? std::max(height(node->left), height(node->right)) + 1 : 0;
}

bool isBalanced(Node *root)
{
    if (!root)
        return true;

    int left = height(root->left);
    int right = height(root->right);

    return std::abs(left - right) < 2 &&
           isBalanced(root->left) &&
           isBalanced(root->right);
}