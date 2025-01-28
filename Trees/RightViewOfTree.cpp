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
// using recursion
// int solve(TreeNode *root, vector<int> &ans, int level)
// {
//     // cout<<ans.size();
//     if (root == nullptr)
//         return 0;
//     int root_val = root->val;
//     if (level == ans.size())
//         ans.push_back(root->val);
//     solve(root->right, ans, level + 1);
//     solve(root->left, ans, level + 1);
//     return 0;
// }

// using level order traversal
int solve(TreeNode *root, vector<int> &ans, int level)
{
    if (root == nullptr)
        return 0;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *current = q.front();
            q.pop();
            if (i == size - 1)
            {
                ans.push_back(current->val);
            }
            if (current->left)
            {
                q.push(current->left);
            }
            if (current->right)
            {
                q.push(current->right);
            }
        }
    }
    return 0;
}

vector<int> rightSideView(TreeNode *root)
{
    vector<int> ans;
    solve(root, ans, 0);
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

    ans = rightSideView(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " \n";
    }
    return 0;
}