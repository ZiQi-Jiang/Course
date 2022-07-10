vector<vector<int>> Print(TreeNode *pRoot)
{
    vector<vector<int>> res;
    if (!pRoot)
        return res;

    queue<TreeNode *> Q;
    Q.push(pRoot);
    while (!Q.empty())
    {
        int curLevelSize = Q.size();
        res.push_back(vector<int>());

        for (int i = 1; i <= curLevelSize; i++)
        {
            auto node = Q.front();
            Q.pop();
            res.back().push_back(node->val);
            if (node->left)
                Q.push(node->left);
            if (node->right)
                Q.push(node->right);
        }
    }
    return res;
}