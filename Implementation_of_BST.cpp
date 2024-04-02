#include <bits/stdc++.h>
#include <cmath>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
        height = 0;
    }
};

class BST
{
public:
    Node *root;
    BST()
    {
        root = nullptr;
    }

    int height(Node *node)
    {
        if (node == nullptr)
        {
            return -1;
        }
        return node->height;
    }

    bool isEmpty()
    {
        return root == nullptr;
    }

    void display()
    {
        display(root, "Root Node");
    }

    void display(Node *node, string details)
    {
        if (node == nullptr)
        {
            return;
        }
        cout << details << node->data << endl;
        display(node->left, "Left Child of :" + to_string(node->data) + " is ");
        display(node->right, "Right Child of : " + to_string(node->data) + " is ");
    }

    void insert(int value)
    {
        root = insert(value, root);
    }

    Node *insert(int value, Node *node)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }
        if (value < node->data)
        {
            node->left = insert(value, node->left);
        }
        else if (value > node->data)
        {
            node->right = insert(value, node->right);
        }
        node->height = max(height(node->left), height(node->right)) + 1;
        return node;
    }

    void populate(int nums[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            insert(nums[i]);
        }
    }

    void populateSorted(int nums[], int start, int end)
    {
        if (start >= end)
        {
            return;
        }
        int mid = (start + end) / 2;
        insert(nums[mid]);
        populateSorted(nums, start, mid);
        populateSorted(nums, mid + 1, end);
    }

    bool isBalance()
    {
        return isBalance(root);
    }

    bool isBalance(Node *node)
    {
        if (node == nullptr)
        {
            return true;
        }
        return abs(height(node->left) - height(node->right)) <= 1 && isBalance(node->left) && isBalance(node->right);
    }
};
int main()
{
    BST tree;
    int arr[7] = {12, 21, 43, 32, 9, 7, 43};
    tree.populate(arr, 7);
    tree.display();
}