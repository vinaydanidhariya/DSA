    #include <bits/stdc++.h>
#include <algorithm>
using namespace std;


bool sortfunc(int a, int b)
{
    if (a < b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    
    int n;
    cin >> n;
    int num;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        nums[i] = num;
    }
    sort(nums.begin(), nums.end(), sortfunc(int a,int  b));
    revers(nums.begin(),nums.end());
    for (int i = 0; i < n; i++)
    {
        cout << nums[i];
    }

    return 0;
}
