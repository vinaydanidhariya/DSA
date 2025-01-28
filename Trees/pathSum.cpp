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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});

        while (!q.empty()) {
            auto [node, currSum] = q.front();
            q.pop();

            if (!node->left && !node->right && currSum == targetSum) {
                return true;
            }

            if (node->left) {
                q.push({node->left, currSum + node->left->val});
            }

            if (node->right) {
                q.push({node->right, currSum + node->right->val});
            }
        }

        return false;
    }



int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    cout << hasPathSum(root, 8);

    return 0;
}