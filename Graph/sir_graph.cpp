#include <bits/stdc++.h>
using namespace std;
// using namespace std::chrono;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef unordered_map<int, int> mii;
typedef unordered_map<int, vi> mivi;
typedef unordered_map<int, mii> mimii;
typedef pair<int, int> pii;
typedef pair<int, vi> pivi;
typedef pair<int, vvi> pivvi;
typedef pair<int, mii> pimii;
typedef vector<pair<int, int>> vpii;

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

void print_vi(vi &v)
{
    forn(i, v.size())
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void print_vvi(vvi &adj_matrix)
{
    forn(i, adj_matrix.size())
    {
        forn(j, adj_matrix[0].size())
        {
            cout << adj_matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

void print_mivi(mivi &m)
{
    for (pivi one_row : m)
    {
        cout << one_row.first << ": ";
        print_vi(one_row.second);
    }
}

pivvi dummy_graph()
{
    int v = 7;
    vvi edges_uw_ud = {{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {3, 6}, {4, 5}, {7, 7}};
    // start , end, weight
    vvi edges_w_d = {{1, 4, 8}, {2, 1, 10}, {2, 6, 7}, {3, 1, 7}, {4, 5, 69}, {5, 2, 8}, {6, 3, 1}, {7, 7, 1}};
    // draw this graph 
    /*
                10
            / 
            2 ----> 1 ----> 4 ----> 5
            / \       |       |
            7   7      69      8
        /     \     |       |
        6 <---- 3    1 <---- 2
    */
    pair<int, vvi> graph_uw_ud = {v, edges_uw_ud}, graph_w_d = {v, edges_w_d};
    return graph_uw_ud;
}

vvi get_adj_matrix(pivvi &graph)
{
    vvi adj_matrix(graph.first, vi(graph.first, 0));
    for (vi edge : graph.second)
    {
        adj_matrix[edge[0] - 1][edge[1] - 1] = 1;
        adj_matrix[edge[1] - 1][edge[0] - 1] = 1;
    }
    return adj_matrix;
}

mivi adj_matrix_to_adj_list_unweighted(vvi &adj_matrix)
{
    mivi adj_list;
    int v = adj_matrix.size();

    forn(i, v)
    {
        adj_list[i + 1] = vi();
    }

    forn(i, v)
    {
        forn(j, v)
        {
            if (adj_matrix[i][j])
            {
                adj_list[i + 1].push_back(j + 1);
            }
        }
    }
    return adj_list;
}

// 4. Convert vvi (adj matrix) to mimii (adj list) weighted
mimii adj_matrix_to_adj_list(vvi &adj_matrix)
{
    mimii adj_list;
    int v = adj_matrix.size();

    forn(i, v)
    {
        adj_list[i + 1] = mii();
    }

    forn(i, v)
    {
        forn(j, v)
        {
            if (adj_matrix[i][j])
            {
                adj_list[i + 1][j + 1] = adj_matrix[i][j];
            }
        }
    }
    return adj_list;
}

void print_mimii(mimii adj_list)
{
    for (pimii one_row : adj_list)
    {
        cout << one_row.first;
        for (pii adj_pair : one_row.second)
        {
            cout << " -> (" << adj_pair.first << ", " << adj_pair.second << ")";
        }
        cout << "\n";
    }
}


void sanitize(mivi &m)
{
    for (auto &ele : m)
    {
        sort(ele.second.begin(), ele.second.end());
    } 
}


vi dfs_graph(mivi adj_list){
    vi dfs;
    stack<int> s;
    s.push(1);
    vb visited(adj_list.size(), false);
    visited[1] = true;
    while(!s.empty()){
        int node = s.top();
        s.pop();
        dfs.push_back(node);
        for(int neighbour : adj_list[node]){
            if(!visited[neighbour]){
                s.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
    return dfs;
}

void solve()
{
    pivvi graph = dummy_graph();
    // cout << graph.first << "\n";
    // vvb adj_matrix = get_adj_matrix(graph);
    vvi adj_matrix = get_adj_matrix(graph);
    // print_vvi(adj_matrix);
    mivi adj_list = adj_matrix_to_adj_list_unweighted(adj_matrix);
    // mimii adj_list = adj_matrix_to_adj_list_unweighted(adj_matrix);
    sanitize(adj_list);
    vi df = dfs_graph(adj_list);
    print_vi(df);
    // print_graph(adj_matrix);
    // print_mimii(adj_list);
    // print_mivi(adj_list);
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