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
    this->left = nullptr;
    this->right = nullptr;
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

void GenericTravel(node *root, string type)
{
    if (!root)
    {
        return;
    }
    if (type == "pre")
    {
        cout << root->val << " ";
    }
    GenericTravel(root->left, type);

    if (type == "in")
    {
        cout << root->val << " ";
    }
    GenericTravel(root->right, type);
    if (type == "post")
    {
        cout << root->val << " ";
    }
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
vector<vector<int>> levelOrder(node *root)
{
    queue<node *> q;
    q.push(root);
    vector<vector<int>> level_wise;
    if (root == nullptr)
        return level_wise;

    while (!q.empty()) // q.size()>0
    {
        int size = q.size();
        vector<int> current_level;
        for (int i = 0; i < size; i++)
        {
            node *current = q.front();
            q.pop();
            current_level.push_back(current->val);
            if (current->left)
            {
                q.push(current->left);
            }
            if (current->right)
            {
                q.push(current->right);
            }
        }
        level_wise.push_back(current_level);
    }
    return level_wise;
}

int maxDepth(node *root)
{
    if (!root)
    {
        return 0;
    }
    int lheight = maxDepth(root->left);
    int rheight = maxDepth(root->right);
    return 1 + max(rheight, lheight);
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

node* vector_to_tree(vector<int> v)
{
    node *root = new node(v[0]);
    root->val = v[0];
    queue<node *> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && v.size() > i)
    {
        q.front()->left = node(v[i]);
        q.push(q.front()->left);
        q.front()->right = node(v[i + 1]);
        q.push(q.front()->right);
        q.pop();
        i = i + 2;
    }
    return root;
}

// BFS level_order
// queue

void level_order(node *root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty()) // q.size()>0
    {
        cout << q.front()->val << " ";
        if (q.front()->left)
        {
            q.push(q.front()->left);
        }
        if (q.front()->right)
        {
            q.push(q.front()->right);
        }
        q.pop();
    }
}

void level_order_wise(node *root)
{
    queue<node *> q;
    q.push(root);
    vector<vector<int>> level_wise;

    while (!q.empty()) // q.size()>0
    {
        int size = q.size();
        vector<int> current_level;
        for (int i = 0; i < size; i++)
        {
            node *current = q.front();
            q.pop();
            current_level.push_back(current->val);
            if (current->left)
            {
                q.push(current->left);
            }
            if (current->right)
            {
                q.push(current->right);
            }
        }
        level_wise.push_back(current_level);
    }

    for (int i = 0; i < level_wise.size(); i++)
    {
        for (int j = 0; j < level_wise[i].size(); j++)
        {
            cout << level_wise[i][j] << " ";
        }
        cout << "\n";
    }
}
// height

// Diameter of a tree
// int height_of_tree(node *root)
// {
//     //     if(!root){
//     //         return ;
//     //     }
// }

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
    cout << "in\n";
    GenericTravel(&root, "in");
    cout << "\nlevel order\n";
    // level_order(&root);
    level_order_wise(&root);
    // int count = height_of_tree(&root);
    // cout << count;
    int maxDepth = maxDepth(&root);
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