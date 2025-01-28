#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int solve(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return {};
    }
    queue<pair<TreeNode *, int>> q;
    map<int, int> topsMap;
    q.push({root, 0});

    while (!q.empty())
    {
        int size = q.size();
        TreeNode *front = q.front().first;
        int dis = q.front().second;
        q.pop();

        if (topsMap.find(dis) == topsMap.end())
        {
            topsMap[dis] = front->val;
        }
        if (front->left)
        {
            q.push({front->left, dis - 1});
        }
        if (front->right)
        {
            q.push({front->right, dis + 1});
        }
    }
    for (auto pkv : topsMap)
    {
        ans.push_back(pkv.second);
    }
    return 0;
}

vector<int> topView(TreeNode *root)
{
    vector<int> ans;
    solve(root, ans);
    return ans;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    vector<int> ans;

    ans = topView(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " \n";
    }
    return 0;
}