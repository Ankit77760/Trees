#include <bits/stdc++.h>
using namespace std;

class BinaryTree
{
private:
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
    Node *root;

public:
    BinaryTree()
    {
        root = nullptr;
    }

    void populate()
    {
        cout << "Enter The Root Node";
        int value;
        cin >> value;
        root = new Node(value);
        populate(root);
    }

    void populate(Node *node)
    {
        cout << "Do you want to enter left of " << node->data << endl;
        bool left;
        cin >> left;
        if (left)
        {
            cout << "Enter The Left Value of " << node->data << endl;
            int value;
            cin >> value;
            node->left = new Node(value);
            populate(node->left);
        }

        cout << "Do You Want To Enter Right of " << node->data << endl;
        bool right;
        cin >> right;
        if (right)
        {
            cout << "Enter The Right Value of " << node->data << endl;
            int value;
            cin >> value;
            node->right = new Node(value);
            populate(node->right);
        }
    }

    void display()
    {
        display(root, "");
    }

    void display(Node *node, string indent)
    {
        if (node == nullptr)
        {
            return;
        }
        cout << indent << node->data << endl;
        display(node->left, indent + "\t");
        display(node->right, indent + "\t");
    }

    void preetydisplay()
    {
        preetydisplay(root, 0);
    }

    void preetydisplay(Node *node, int level)
    {
        if (node == nullptr)
        {
            return;
        }
        preetydisplay(node->right, level + 1);
        if (level != 0)
        {
            for (int i = 0; i < level - 1; i++)
            {
                cout << "\t\t";
            }
            cout << "-------------" << node->data << endl;
        }
        else
        {
            cout << node->data << endl;
        }
        preetydisplay(node->left, level + 1);
    }

    void preOrder()
    {
        preOrder(root);
        cout << "Pre Order";
    }

    void preOrder(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        cout << node->data;
        preOrder(node->left);
        preOrder(node->right);
    }

    void postOrder()
    {
        postOrder(root);
        cout << "Post Order";
    }

    void postOrder(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data;
    }

    void inOrder()
    {
        inOrder(root);
        cout << "In Order";
    }

    void inOrder(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        inOrder(node->left);
        cout << node->data;
        inOrder(node->right);
    }
};

int main()
{
    BinaryTree tree;
    tree.populate();
    tree.display();
    tree.preetydisplay();
}