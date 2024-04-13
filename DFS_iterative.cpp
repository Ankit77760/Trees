void dfs(TreeNode *node)
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