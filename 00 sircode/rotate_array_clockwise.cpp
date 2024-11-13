#include <bits/stdc++.h>
using namespace std;
// using namespace std::chrono;

typedef vector<int> vi;
typedef vector<string> vs;
typedef map<int, int> mii;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < n; i++)

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

void rotate_vec_cw_one_time(vi &v) // SC: O(1), TC: O(n), k=1
{
    int temp = v[v.size() - 1];             // O(1)
    for (int i = v.size() - 2; i > -1; i--) // O(n) * O(1) = O(n)
    {
        v[i + 1] = v[i];
    }
    v[0] = temp; // O(1)
}

void rotate_vec_cw_k_time(vi &v, int k)
{
    forn(i, k) // O(k) * O(n) = O(nk)
    {
        rotate_vec_cw_one_time(v); //O(n)
    }
}

void shift_k_places(vi &v, int k) // SC: O(k), TC: O(n+k)
{
    int n = v.size();
    // store the last k places
    vi temp(k);
    for (int i = n - k; i < n; i++) // O(k) * 1 = O(k)
    {
        temp[i - (n - k)] = v[i];
    }

    // shift the initial (n-k) places to right
    for (int i = n - k - 1; i > -1; i--) // O(n-k)
    {
        v[i + k] = v[i];
    }

    //  insert the saved k at beginning
    forn(i, k) // O(k)
    {
        v[i] = temp[i];
    }
}

void double_reversal(vi &v, int k) //sc : O(1), TC: O(n), k=1
{
    reverse(v.begin(), v.end());
    reverse(v.begin(), v.begin() + k);
    reverse(v.begin() + k, v.end());
}

void solve()
{
    vi v = input_vector();
    int k;
    cin >> k;
    double_reversal(v, k);
    print_vec(v);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    // auto start = high_resolution_clock::now();
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<nanoseconds>(stop - start);
    // cout << duration.count() << "\n";
}