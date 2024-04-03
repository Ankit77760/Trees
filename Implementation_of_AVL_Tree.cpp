#include <bits/stdc++.h>
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
    }
};

class AVL
{
public:
    int max(int a, int b)
    {
        (a > b) ? a : b;
    }
    Node *root;
    AVL()
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
        display(root, "Root Node: ");
    }

    void display(Node *node, string detail)
    {
        if (node == nullptr)
        {
            return;
        }
        cout << detail << node->data << endl;
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
        return rotate(node);
    }

    Node *rotate(Node *node)
    {
        int balanceFactor = (height(node->left) - height(node->right));
        if (balanceFactor > 1)
        {
            if (height(node->left->left) >= height(node->left->right))
            {
                // left left case
                return rotateRight(node);
            }
            else
            {
                // left Right Case
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }
        else if (balanceFactor < -1)
        {
            if (height(node->right->right) >= height(node->right->left))
            {
                // right right case
                return rotateLeft(node);
            }
            else
            {
                // right left case
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }
        return node;
    }

    Node *rotateLeft(Node *c)
    {
        Node *p = c->right;
        Node *t = p->left;

        p->left = c;
        c->right = t;

        p->height = max(height(p->left), height(p->right)) + 1;
        c->height = max(height(c->left), height(c->right)) + 1;

        return p;
    }

    Node *rotateRight(Node *p)
    {
        Node *c = p->left;
        Node *t = c->right;

        c->right = p;
        p->left = t;

        p->height = max(height(p->left), height(p->right)) + 1;
        c->height = max(height(c->left), height(c->right)) + 1;
        return c;
    }

    void populate(int nums[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            insert(nums[i]);
        }
    }

    void populateSort(int nums[], int start, int end)
    {
        if (start >= end)
        {
            return;
        }
        int mid = (start + end) / 2;
        insert(nums[mid]);
        populateSort(nums, start, mid);
        populateSort(nums, mid + 1, end);
    }

    bool isBalance()
    {
        isBalance(root);
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
    AVL Tree;
    int nums[7] = {1, 2, 3, 4, 5, 6, 7};
    Tree.populate(nums, 7);
    Tree.display();
}