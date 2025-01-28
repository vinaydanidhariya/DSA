#include <bits/stdc++.h>
using namespace std;
// using namespace std::chrono;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef map<int, int> mii;
typedef pair<int, int> pii;
// typedef pair<int, vvi> pivvi;
typedef vector<pair<int, int>> vpii;
typedef map<int, vi> mivi;
typedef map<int, map<int, int>> mimii;

#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define flf(i, a, b) for (int i = a; i < b; i++)
#define flb(i, a, b) for (int i = a; i > b; i--)
#define takeInt(n) \
    int n;         \
    cin >> n
#define forn(i, n) flf(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()

const int MOD = 1e9 + 7;
const long long INF = 1e18;

vi input_vector()
{
    int n;
    cin >> n;
    vi v(n);
    forn(i, n)
    {
        cin >> v[i];
    }
    return v;
}

void print_vec(vi &v)
{
    forn(i, v.size())
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

pair<int, vvi> dummy_graph()
{
    int v = 7;
    // undirected unweighted
    // vvi edges = {{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {3, 6}, {4, 5}};
    // directed weighted
    // vvi edges = {{1,4,1}, {1,2,1}, {2,3,1}, {3,4,1}, {4,5,1}, {5,6,1}, {6,7,1}, {7,5,1}};
    // undirected unweighted
    // vvi edges = {{1,3},{1,4},{2,5},{2,6},{2,1},{3,6},{4,1},{5,4},{6,3}};
    // undirected weighted
    vvi edges = {{1,2,10},{1,3,7},{1,4,2},{2,5,8},{2,6,7},{3,6,1},{4,5,69},{5,6,15}};
    // adjacency list
    // mii adj_list = {{1, {2, 3, 4}}, {2, {1, 5, 6}}, {3, {1, 6}}, {4, {1, 5}}, {5, {2, 4}}, {6, {2, 3}}, {7, {5, 6}}};
    // MIMII

    pair<int, vvi> graph = {v, edges};
    return graph;
}
// can you convert this to a matrix 

// this is for unweighted graph and undirected
mivi graph_to_adj_list(pair<int, vvi> &graph){
    mivi adj_list;

    int vertices = graph.first;
    vvi edges = graph.second;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    return adj_list;
}

// this is for weighted graph
mimii graph_to_adj_list(pair<int, vvi> &graph){
    mimii adj_list;
    int vertices = graph.first;
    vvi edges = graph.second;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        adj_list[u][v] = weight;
        adj_list[v][u] = weight;
    }
    return adj_list;
}

// this is for unweighted graph


// 1. Convert map<int, vector<int>> (adj list) to vvi (adj matrix)
vvi adj_list_to_matrix(mii &adj_list, int vertices, bool directed = false)
{
    vvi matrix(vertices, vi(vertices, 0));
    for (auto &entry : adj_list)
    {
        int u = entry.first;
        for (int v : entry.second)
        {
            matrix[u - 1][v - 1] = 1;
            if (!directed)
            {
                matrix[v - 1][u - 1] = 1;
            }
        }
    }
    return matrix;
}

// 2. Convert map<int, map<int, int>> (adj list) to vvi (adj matrix)
vvi adj_list_to_matrix(mimii &adj_list, int vertices)
{
    vvi matrix(vertices, vi(vertices, 0));
    for (auto &entry : adj_list)
    {
        int u = entry.first;
        for (auto &inner_entry : entry.second)
        {
            int v = inner_entry.first;
            int weight = inner_entry.second;
            matrix[u - 1][v - 1] = weight;
        }
    }
    return matrix;
}

// 3. Convert vvi (adj matrix) to map<int, vector<int>> (adj list)
mii matrix_to_adj_list(vvi &matrix)
{
    mii adj_list;
    int vertices = matrix.size();
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (matrix[i][j] != 0)
            {
                adj_list[i + 1].push_back(j + 1);
            }
        }
    }
    return adj_list;
}

// 4. Convert vvi (adj matrix) to map<int, map<int, int>> (adj list)
mimii matrix_to_weighted_adj_list(vvi &matrix)
{
    mimii adj_list;
    int vertices = matrix.size();
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (matrix[i][j] != 0)
            {
                adj_list[i + 1][j + 1] = matrix[i][j];
            }
        }
    }
    return adj_list;
}

void print_vvb(vvb &vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        for (size_t j = 0; j < vec[0].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << "\n";
    }
}

vvb get_adj_matrix(pair<int, vvi> &graph)
{
    int vertices = graph.first;
    vvi edges = graph.second;
    vvb matrix(vertices, vb(vertices, 0));
    for (int k = 0; k < edges.size(); k++)
    {
        int i = edges[k][0];
        int j = edges[k][1];

        matrix[i - 1][j - 1] = 1;
        matrix[j - 1][i - 1] = 1;
    }
    return matrix;
}


// HW Questions Graphs 
// 1. Convert mivi (adj list) to vvi (adj matrix)
// 2. Convert mimii (adj list) to vvi (adj matrix)
// 3. Convert vvi (adj matrix) to mivi (adj list)
// 4. Convert vvi (adj matrix) to mimii (adj list)

// Convert mimii (adj list) to vvi (adj matrix)
vvi adj_list_to_matrix(mimii &adj_list, int vertices)
{
    vvi matrix(vertices, vi(vertices, 0));
    for (auto &entry : adj_list)
    {
        int u = entry.first;
        for (auto &inner_entry : entry.second)
        {
            int v = inner_entry.first;
            int weight = inner_entry.second;
            matrix[u - 1][v - 1] = weight;
        }
    }
    return matrix;
}

// 3. Convert vvi (adj matrix) to mivi (adj list)
mivi matrix_to_adj_list(vvi &matrix)
{
    mivi adj_list;
    int vertices = matrix.size();
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (matrix[i][j] != 0)
            {
                adj_list[i + 1].push_back(j + 1);
            }
        }
    }
    return adj_list;
}

void print_mivi(mivi &adj_list)
{
    for (auto &entry : adj_list)
    {
        cout << entry.first << ": ";
        for (int v : entry.second)
        {
            cout << v << " ";
        }
        cout << "\n";
    }
}


// 3. Convert vvi (adj matrix) to mivi (adj list)
vvi graph_to_adj_matrix(pair<int, vvi> &graph){
    int vertices = graph.first;
    vvi edges = graph.second;
    vvi matrix(vertices, vi(vertices, 0));
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        matrix[u - 1][v - 1] = weight;
        matrix[v - 1][u - 1] = weight;
    }
    return matrix;
}

mivi adj_matrix_to_list(vvi &matrix)
{
    mivi adj_list;
    int vertices = matrix.size();
    for (int i = 0; i < vertices; i++)
    {
        // j-> i ,i+1,0
        for (int j = 0; j < vertices; j++)
        {
            if (matrix[i][j] != 0)
            {
                adj_list[i + 1].push_back(j + 1);
            }
        }
    }
    return adj_list;
}


// 1. Convert mivi (adj list) to vvi (adj matrix)
// 2. Convert mimii (adj list) to vvi (adj matrix)

// 4. Convert vvi (adj matrix) to mimii (adj list)






void solve()
{
    pair<int, vvi> graph = dummy_graph();
    // mivi adj_list = graph_to_adj_list(&graph);
    vvi adj_list = graph_to_adj_matrix(&graph);
    adj_matrix_to_list
    // print_vvb(adj_matrix);
}

int main()
{
    fastIO;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    // auto start = high_resolution_clock::now();
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<nanoseconds>(stop - start);
    // cout << duration.count() << "\n";
}