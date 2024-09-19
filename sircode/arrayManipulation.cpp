#include <bits/stdc++.h>
using namespace std;
// using namespace std::chrono;

typedef vector<int> vi;
typedef vector<string> vs;
typedef map<int, int> mii;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < n; i++)

int gcd(int a, int b)
{
    if (a < b)
    {
        swap(a, b);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

void print_array(int *a, int n)
{
    forn(i, n)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

void juggling_array(int *a, int l, int r, int k)
{
    int n = r + 1 - l;
    int number_of_cycles = gcd(n, k);
    int length_of_cycle = n / number_of_cycles;

    // cout << number_of_cycles << " " << length_of_cycle << "\n";

    forn(i, number_of_cycles)
    {
        // work on each cycle
        int temp = a[i];
        for (int j = 0, count = 0; count < length_of_cycle; j = (j + k) % n, count++)
        {
            a[i + j] = a[(i + j + k) % n];
        }
        a[(i + n - k) % n] = temp;
    }
    print_array(a, n);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    forn(i, n)
    {
        cin >> a[i];
    }
    juggling_array(a, 0, n - 1, k);
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