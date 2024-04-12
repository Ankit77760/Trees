boolean findPath(TreeNode *root, vector<int> &path)
{
    if (root == nullptr)
    {
        return arr.lenght == 0;
    }
    return helper(root, path, 0);
}

boolean helper(TreeNode *node, vector<int> path, int index)
{
    if (node == nullptr)
    {
        return false;
    }
    if (index > path.size() || node->data != path[index])
    {
        return false;
    }

    if (node->left == nullptr && node->right == nullptr && index == path.size() - 1)
    {
        return true;
    }

    return helper(node->left, path, index + 1) || helper(node->right, path, index + 1);
}