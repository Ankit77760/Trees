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

Node *createNodeByLevelOrderTraversal(vector<int> &arr)
{
    Node *root = new Node(arr[0]);
    queue<Node *> q;
    q.push(root);

    for (int i = 1; i < arr.size(); i = i + 2)
    {
        Node *current = q.front();
        q.pop();
        if (i < arr.size() && arr[i] != -1)
        {

            current->left = new Node(arr[i]);
            q.push(current->left);
        }

        if (i + 1 < arr.size() && arr[i + 1] != -1)
        {
            current->right = new Node(arr[i + 1]);
            q.push(current->right);
        }
    }
    return root;
}

void inOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data;
    inOrder(root->right);
}

void BFS(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();
        cout << current->data;
        if (current->left)
        {
            q.push(current->left);
        }

        if (current->right)
        {
            q.push(current->right);
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, -1, -1, -1};
    Node *root = createNodeByLevelOrderTraversal(arr);
    inOrder(root);
    cout << endl;
    BFS(root);
}