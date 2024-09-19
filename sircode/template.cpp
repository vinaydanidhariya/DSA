#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define flf(i, a, b) for (int i = a; i < b; i++)
#define flb(i, a, b) for (int i = a; i > b; i--)
#define takeInt(n) \
    int n;         \
    cin >> n;
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

int partition(vector<int> &arr, int left, int right)
{
    int pivot = arr[left];
    int i = left;
    int j = right;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= right - 1)
        {
            i++;
        }
        while (arr[j] > pivot && j >= left + 1)
        {
            j--;
        }
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[left], arr[j]);
    return j;
}

void qs(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int partitionIndex = partition(arr, left, right);
        qs(arr, left, partitionIndex - 1);
        qs(arr, partitionIndex + 1, right);
    }
}

void solve()
{
    vi nums = input_vector();
    qs(nums, 0, nums.size() - 1);
    print_vec(nums);
}

int main()
{
    fastIO;
    int t = 1;
    // cin >> t;
    auto start = high_resolution_clock::now();
    while (t--)
    {
        // solve();
        for (int i = 0; i < 100000000; i++)
        {
            
        }
        
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << duration.count() << "\n";
}