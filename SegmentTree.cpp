// created a segment tree for finding the sum of range element
#include <bits/stdc++.h>
using namespace std;

struct Node
{
public:
    int data;
    Node *left;
    Node *right;
    int startInterval;
    int endInterval;
    Node(int startInterval, int endInterval)
    {
        this->startInterval = startInterval;
        this->endInterval = endInterval;
    }
};

class segmentTree
{
public:
    Node *root;
    segmentTree(int arr[], int n)
    {
        // Create a tree using the given array
        root = constructTree(arr, 0, n - 1);
    }

    ~segmentTree()
    {
        delete root;
    }

    Node *constructTree(int arr[], int start, int end)
    {
        // leaf node
        if (start == end)
        {
            Node *leaf = new Node(start, end);
            leaf->data = arr[start];
            return leaf;
        }

        // create new node with index you are at for range of node
        Node *node = new Node(start, end);
        int mid = (start + end) / 2;

        node->left = constructTree(arr, start, mid);
        node->right = constructTree(arr, mid + 1, end);

        // for top most sum of all and so on
        node->data = (node->left->data) + (node->right->data);
    }

    void display()
    {
        display(root);
    }

    void display(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        if (node->left != nullptr)
        {
            cout << "Interval=[" << node->left->startInterval << node->left->endInterval << "] and data: " << node->left->data << endl;
        }
        else
        {
            cout << "No Left Child" << endl;
        }

        if (node->right != nullptr)
        {
            cout << "Interval=[" << node->right->startInterval << node->right->endInterval << "] and data: " << node->right->data << endl;
        }
        else
        {
            cout << "No Right Child" << endl;
        }
        cout << endl;
        display(node->left);
        display(node->right);
    }

    int query(int qsi, int qei)
    {
        return query(root, qsi, qei);
    }

    int query(Node *node, int qsi, int qei)
    {
        if (node == nullptr)
        {
            return 0;
        }

        if (node->startInterval >= qsi && node->endInterval <= qei)
        {
            // completely inside the given range;
            return node->data;
        }
        else if (node->startInterval > qei || node->endInterval < qsi)
        {
            // completely outside the range
            return 0;
        }
        else
        {
            return query(node->left, qsi, qei) + query(node->right, qsi, qei);
        }
    }

    void update(int index, int value)
    {
        update(root, index, value);
    }
    void update(Node *node, int index, int value)
    {
        if (node == nullptr)
        {
            return;
        }
        if (index > node->startInterval && index <= node->endInterval)
        {
            if (index == node->startInterval && index == node->endInterval)
            {
                node->data = value;
            }
        }
        else
        {
            update(node->left, index, value);
            update(node->right, index, value);
            node->data = (node->left->data) + (node->right->data);
        }
    }
}

;

int main()
{
    int arr[8] = {3, 8, 6, 7, -2, -8, 4, 9};
    segmentTree Tree(arr, 8);
    Tree.display();
}