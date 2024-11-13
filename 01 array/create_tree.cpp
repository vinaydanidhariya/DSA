#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int val;
    node *left;
    node *right;

public:
    node(int val);
    node(int val, node *left, node *right);
};

node::node(int val)
{
    this->val = val;
}

node::node(int val, node *left, node *right)
{
    this->val = val;
    this->left = left;
    this->right = right;
}

node createTree()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    return *root;
}
void pre_order(node *root)
{
    if (!root)
    {
        return;
    }

    cout << root->val << " ";
    pre_order(root->left);
    pre_order(root->right);
}
void in_order(node *root)
{
    if (!root)
    {
        return;
    }

    in_order(root->left);
    cout << root->val << " ";
    in_order(root->right);
}
void post_order(node *root)
{
    if (!root)
    {
        return;
    }

    post_order(root->left);
    post_order(root->right);
    cout << root->val << " ";
}
// level order
void BFSUtil(node *root, int level)
{
    if (!root)
    {
        return;
    }
    if (level == 1)
    {
        cout << root->val << " ";
    }
    else if (level > 1)
    {
        BFSUtil(root->left, level - 1);
        BFSUtil(root->right, level - 1);
    }
}

int height(node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);

        if (lheight > rheight)
        {
            return (lheight + 1);
        }
        else
        {
            return (rheight + 1);
        }
    }
}

void BFS(node *root)
{
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        BFSUtil(root, i);
    }
}


void DFS(node *root)
{
    if (!root)
    {
        return;
    }
    cout << root->val << " ";
    DFS(root->left);
    DFS(root->right);
}
// Diameter (width) of a tree


int main()
{
    // int n;
    // cin >> n;
    // vector<int> nums(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> nums[i];
    // }

    node root = createTree();
    pre_order(&root);
    cout << "\n";
    in_order(&root);
    cout << "\n";
    post_order(&root);
    cout << "\n";
    BFS(&root);
    cout << "\n";
}

//   1
//   /\
//  2  3
//  /\  /\
// 4  5 6 7

// pre ROOT LEFT RIGHT
// 1 2 4 5 3 6 7
// in  LEFT ROOT RIGHT
// 4 2 5 1 6 3 7
// post LEFT RIGHT ROOT
// 4 5 2 6 7 3 1