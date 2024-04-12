vector<vector<int> > paths(TreeNode *root, int sum)
{
    vector<vector<int> > ans;
    vector<int> temp;
    helper(root, sum, ans, temp);
    return ans;
}

void helper(TreeNode *node, int sum, vector<vector<int> > &ans, vector<int> &temp)
{
    if (node == nullptr)
    {
        return;
    }

    temp.push_back(node->data);

    if (node->data == sum && node->left == nullptr && node->right == nullptr)
    {
        ans.push_back(temp);
    }
    else
    {
        helper(node->left, sum - node->data, ans, temp);
        helper(node->right, sum - node->data, ans, temp);
    }
    temp.pop_back();
}