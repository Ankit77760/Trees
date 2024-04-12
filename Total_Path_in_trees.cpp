int count paths(TreeNode *node, int summ)
{
    vector<int> pathcurr;
    return helper(node, summ, pathcurr);
}

int helper(TreeNode *node, int summ, vector<int> &pathcurr)
{
    if (node == nullptr)
    {
        return 0;
    }
    int count = 0;
    pathcurr.push_back(node->data);
    int sum = 0;
    for (int i = pathcurr.size(); i >= 0; i--)
    {
        sum += pathcurr[i];
        if (sum == summ)
        {
            count++;
        }
    }
    count += helper(node->left, sum, pathcurr) + helper(node->right, sum, pathcurr);
    pathcurr.pop_back();
    return count;
}