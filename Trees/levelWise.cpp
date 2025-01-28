#include <bits/stdc++.h>
using namespace std;
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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if (root == nullptr) return level_wise;
        q.push(root);
        vector<vector<int>> level_wise;

        while (!q.empty()) // q.size()>0
        {
            int size = q.size();
            vector<int> current_level;
            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                q.pop();
                current_level.push_back(current->val);
                if (current->left) {
                    q.push(current->left);
                }
                if (current->right) {
                    q.push(current->right);
                }
            }
            level_wise.push_back(current_level);
        }
        return level_wise;
    }
    
};