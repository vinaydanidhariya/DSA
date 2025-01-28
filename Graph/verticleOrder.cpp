/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};
struct NodeInfo {
    TreeNode* node;
    int vertical;
    int level;
    NodeInfo(TreeNode* n, int v, int l) : node(n), vertical(v), level(l) {}
};

vector<vector<int>> verticalTraversal(TreeNode* root) {
    if (!root) return {};

    map<int, map<int, multiset<int>>> nodes;
    queue<NodeInfo> q;
    q.push(NodeInfo(root, 0, 0));

    while (!q.empty()) {
        NodeInfo info = q.front();
        q.pop();
        nodes[info.vertical][info.level].insert(info.node->val);

        if (info.node->left) {
            q.push(NodeInfo(info.node->left, info.vertical - 1, info.level + 1));
        }
        if (info.node->right) {
            q.push(NodeInfo(info.node->right, info.vertical + 1, info.level + 1));
        }
    }

    vector<vector<int>> result;
    for (auto& p : nodes) {
        vector<int> col;
        for (auto& q : p.second) {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        result.push_back(col);
    }

    return result;
}

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return {};
    }
    queue<pair<TreeNode *, int>> q;
    map<int, vector<int>> topsMap;
    q.push({root, 0});
    vector<vector<int>> levels;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++)
        {
            TreeNode *front = q.front().first;
            int dis = q.front().second;
            q.pop();
            level.push_back(front->val);
            topsMap[dis].push_back(front->val);
            if (front->left)
            {
                q.push({front->left, dis - 1});
            }
            if (front->right)
            {
                q.push({front->right, dis + 1});
            }
        }
        cout << "\n";
        levels.push_back(level);
        sort(level.begin(), level.end());
    }
    for (auto level : levels)
    {
        for (auto val : level)
        {
            cout << val << " ";
        }
        cout << "\n";
    }
    vector<vector<int>> vvi;
    for (auto pkv : topsMap)
    {
        sort(pkv.second.begin(), pkv.second.end());
        vvi.push_back(pkv.second);
    }
    return vvi;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    vector<vector<int>> vvi = verticalTraversal(root);
    for (auto level : vvi)
    {
        for (auto val : level)
        {
            cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}