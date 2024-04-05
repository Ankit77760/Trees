#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

Node *successorNode(Node *root, int key)
{
    if (root == nullptr)
    {
        return root;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        if (curr->data == key)
        {
            q.pop();
            Node *temp = q.front();
            cout << temp->data;
            return curr;
        }
        q.pop();

        if (curr->left)
        {
            q.push(curr->left);
        }
        if (curr->right)
        {
            q.push(curr->right);
        }
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    successorNode(root, 4);
}