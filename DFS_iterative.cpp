// iterative preorder dfs
// root left right
void preorder(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }
    stack<TreeNode *> s1;
    s1.push(node);

    while (!st.empty())
    {
        TreeNode *curr = s1.top();
        s1.pop();

        cout << curr->data;

        if (curr->right)
        {
            s1.push(curr->right);
        }
        if (curr->left)
        {
            s1.push(curr->left);
        }
    }
}

// iterative inorder dfs
// left root right
void inorder(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    stack<TreeNode *> s1;
    TreeNode *curr = root;

    while (curr != nullptr || !s1.empty())
    {
        while (curr != nullptr)
        {
            s1.push(curr);
            curr = curr->left;
        }
    }
    current = s1.top();
    s1.pop();

    cout << curr->data;
    s1.push(curr->right);
}

// iterative postorder dfs
// left right root
void postorder(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    stack<TreeNode *> st1, st2;
    st1.push(root);

    while (!st1.empty())
    {
        TreeNode *curr = st1.top();
        st1.pop();

        st2.push(curr);
        if (curr->left != nullptr)
        {
            st1.push(curr->left);
        }
        if (curr->right != nullptr)
        {
            st1.push(curr->right);
        }
    }

    while (!st2.empty())
    {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}