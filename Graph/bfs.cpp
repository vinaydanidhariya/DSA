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

void sanitize(mivi &adj_list)
{
    for (auto &pair : adj_list)
    {
        sort(all(pair.second));
    }
}

vi helper_bfs(int node, mivi &adj_list, vb &visited)
{
    vi bfs;
    queue<int> q;
    q.push(node);
    // visited[node] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        visited[node] = true;
        bfs.push_back(node);
        for (int neighbour : adj_list[node])
        {
            if (!visited[neighbour])
            {
                q.push(neighbour);
                // visited[neighbour] = true;
            }
        }
    }
    return bfs;
}

vi bfs(int node, mivi &adj_list)
{
    vb visited(adj_list.size(), false);
    for (int i = 1; i < adj_list.size(); i++)
    {
        if (!visited[i])
        {
            return helper_bfs(i, adj_list, visited);
        }
    }
    return helper_bfs(node, adj_list, visited);
}

mivi graph_PairIntVvi_to_vvi_adj_list(pair<int, vvi> &graph)
{
    int vertices = graph.first;
    vvi edges = graph.second;
    mivi adj_list(vertices + 1); // resize for 1-based indexing

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj_list[u].pb(v);
        if (u != v)
            adj_list[v].pb(u);
    }
    return adj_list;
}

// Sample graph generator
pair<int, vvi> dummy_graph()
{
    int v = 7;
    // undirected unweighted
    // vvi edges = {{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {3, 6}, {4, 5}};
    // directed weighted
    // vvi edges = {{1,4,1}, {1,2,1}, {2,3,1}, {3,4,1}, {4,5,1}, {5,6,1}, {6,7,1}, {7,5,1}};
    // undirected unweighted
    vvi edges = {{1, 3}, {1, 4}, {2, 5}, {2, 6}, {2, 1}, {3, 6}, {5, 4}, {7, 7}};
    // undirected weighted
    // vvi edges = {{1,2,10},{1,3,7},{1,4,2},{2,5,8},{2,6,7},{3,6,1},{4,5,69},{5,6,15}};
    // adjacency list
    // mii adj_list = {{1, {2, 3, 4}}, {2, {1, 5, 6}}, {3, {1, 6}}, {4, {1, 5}}, {5, {2, 4}}, {6, {2, 3}}, {7, {5, 6}}};
    // MIMII

    pair<int, vvi> graph = {v, edges};
    return graph;
}

void print_mivi(mivi &m)
{
    for (auto one_row : m)
    {
        cout << one_row.first << ": ";
        print_vi(one_row.second);
    }
}

int main()
{
    fastIO;

    pivvi graph = dummy_graph();
    mivi adj_list = graph_PairIntVvi_to_vvi_adj_list(graph);

    sanitize(adj_list);
    print_mivi(adj_list);
    // start,edges,
    vi df = bfs(1, adj_list);
    print_vi(df);

    return 0;
}
