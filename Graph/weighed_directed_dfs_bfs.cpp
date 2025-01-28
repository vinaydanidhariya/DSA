#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair<int, vi> pivi;
typedef unordered_map<int, vi> mivi;
typedef pair<int, vvi> pivvi;
typedef map<int, map<int, int>> mimii;

void print_vi(vi &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void print_vvi(vvi &adj_matrix)
{
    for (int i = 0; i < adj_matrix.size(); i++)
    {
        for (int j = 0; j < adj_matrix[0].size(); j++)
        {
            cout << adj_matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

// void sanitize(mimii &adj_list)
// {
//     for (auto &pair : adj_list)
//     {
//         sort(all(pair.second));
//     }
// }



void print_mimii(mimii &adj_list)
{
    for (auto one_row : adj_list)
    {
        cout << one_row.first << ": ";
        for (auto one_col : one_row.second)
        {
            cout<<"{";
            cout << one_col.first << " ";
            cout<<"weight : "<<one_col.second;
            cout<<"} ";
        }
        cout << "\n";
    }
}

void helper_dfs(int node,mimii &adj, vector<int> &visited, vector<int> &ls)
{

    visited[node] = 1;
    ls.push_back(node);
    // traverse all its neighbors
    for (auto it : adj[node])
    {
        // if the neighbour is not visited
        if (!visited[it.first])
        {
            helper_dfs(it.first, adj, visited, ls);
        }
    }  
}

vector<int> dfs(mimii &adj_list)
{
    vector<int> ls;
    vector<int> visited(adj_list.size() + 1, 0); // +1 for 1-based indexing
    helper_dfs(1, adj_list, visited, ls);
    for (int i = 1; i < visited.size(); i++)
    {
        if (!visited[i])
        {
            helper_dfs(i, adj_list, visited, ls);
        }
    }
    return ls;
}

mimii graph_pivii_to_mimii_adj_list(pair<int, vvi> &graph)
{
    int vertices = graph.first;
    vvi edges = graph.second;
    mimii adj_list; // resize for 1-based indexing

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj_list[u][v] = w;
    }
    return adj_list;
}

// Sample graph generator
pair<int, vvi> dummy_graph()
{
    int v = 7;
    vvi edges_uw_ud = {{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {3, 6}, {4, 5}, {7, 7}};
    // start , end, weight
    vvi edges_w_d = {{1, 4, 8}, {2, 1, 10}, {2, 6, 7}, {3, 1, 7}, {4, 5, 69}, {5, 2, 8}, {6, 3, 1}, {7, 7, 1}};

    pair<int, vvi> graph_uw_ud = {v, edges_uw_ud},

                   graph_w_d = {v, edges_w_d};

    return graph_w_d;
    // return graph;
}


int main()
{
    fastIO;

    pivvi graph = dummy_graph();
    mimii adj_list = graph_pivii_to_mimii_adj_list(graph);

    // sanitize(adj_list);
    print_mimii(adj_list);
    vi df = dfs(adj_list);
    print_vi(df);

    return 0;
}
