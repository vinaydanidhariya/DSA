/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        // BASE CASE
        if (!root)
            return 0;

        queue<pair<TreeNode *, long long>> q;

        long long ans = 0;
        q.push({root, 0});

        while (!q.empty())
        {
            int k = q.size();
            long long mini = q.front().second;
            long long first, last;

            for (int i = 0; i < k; i++)
            {
                long long curr = q.front().second - mini;
                TreeNode *node = q.front().first;
                q.pop();

                if (i == 0)
                    first = curr;

                if (i == k - 1)
                    last = curr;

                if (node->left)
                    q.push({node->left, 2 * curr + 1});

                if (node->right)
                    q.push({node->right, 2 * curr + 2});
            }
            ans = max(ans, last - first + 1);
        }

        return ans;
    }
};