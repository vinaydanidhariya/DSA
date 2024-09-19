#include <bits/stdc++.h>
using namespace std;
// using namespace std::chrono;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

using namespace std;

vi insertion_sort(< vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        int key = v[i];
        for (int j = 0; j < i; j++)
        {
            int temp;
            if (key > v[i])
            {
                temp = v[i];
                v[i] = v[j];
                v[j] = v[i];
            }
        }
    }
    return v;
}

int main()
{
    vi num = {1, 2, 3, 64, 8, 42, 5, 4, 5, 4};
    insertion_sort(num);
    for (int i = 0; i < num.size(); i++)
    {
        cout <<num[i]<<endl     ;
    }

    return 0;
}