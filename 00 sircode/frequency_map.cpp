#include <bits/stdc++.h>
using namespace std;
// using namespace std::chrono;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef map<int, int> mii;
typedef unordered_map<int, int> umii;
typedef pair<int, int> pii;
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

void print_map(umii &m)
{
    for (pii pkv : m)
    {
        cout << pkv.first << ": " << pkv.second << "\n";
    }
}

void get_frequencies(vi &v) // TC: O(max(n, max_e)), SC: O(max_e    )
{
    // find the max element of v
    // int max_e = max(vi(v.begin(), v.end()));
    int max_e = *max_element(v.begin(), v.end()); // O(n)
    // int val = max({1, 2, 3, 4, 5});
    // cout << max_e << "\n";

    // create another vec of size max + 1
    vi counts(max_e + 1); // O (1)

    // increase the counts
    for (int x : v) // O(n)
    {
        counts[x]++;
    }

    // print results
    forn(i, max_e + 1) // O (max_e)
    {
        if (counts[i])
        {
            cout << i << ": " << counts[i] << "\n";
        }
    }
}

umii get_frequency_map(vi &v) // TC: O(n), SC: O(n)
{
    umii counts;
    for (int x : v) // O(n)
    {
        counts[x]++;
    }
    return counts;
}

void solve()
{
    vi v = input_vector();
    umii counts = get_frequency_map(v);
    print_map(counts);
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