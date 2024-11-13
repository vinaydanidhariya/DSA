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

void shift3()
{
    // TC: O(n), 1<=k<2; SC: O(min(k,n-k))
}

void double_reversal(vi &a, int k)
{
    // TC: O(n), k=1 ; SC: O(1)
    reverse(a.begin(), a.end());
    reverse(a.begin(), a.begin() + k);
    reverse(a.begin() + k, a.end());

    print_vec(a);
}

void juggling_algo()
{
    // TC: O(n), k=1 ; SC: O(1)
}

void shift2(vector<int> &a, int k) // TC: O(n), k=1, SC: O(n)
{
    // 1 2 3 4 5 // k = 2
    // 4 5 1 2 3
    int n = a.size();
    vector<int> ans(n);
    for (int i = 0; i < k; i++) // O(k) * 1 = O(k)
    {
        ans[i] = a[i + (n - k)];
    }                           // 4 5 _
    for (int i = k; i < n; i++) // O(n-k)
    {
        ans[i] = a[i - k];
    }
    print_vec(ans); // O(n)
}

void solve()
{
    // 1 2 3 4 5
    // 5 1 2 3 4
    vi a = input_vector();
    int k;
    cin >> k;

    double_reversal(a, k);
    // write code

    // forn(count, k)
    // {
    //     int temp = a[a.size() - 1];
    //     for (int i = a.size() - 1; i > 0; i--)
    //     {
    //         a[i] = a[i - 1];
    //     }
    //     a[0] = temp;
    // }

    // // print output
    // print_vec(a);
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