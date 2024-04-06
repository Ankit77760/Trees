#include <bits/stdc++.h>
using namespace std;

struct Node
{
public:
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

void printRight(Node *root)
{
    vector<int> ans;
    if (root == nullptr)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            Node *current = q.front();
            q.pop();

            if (i == size - 1)
            {
                ans.push_back(current->data);
            }
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
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    printRight(root);
}