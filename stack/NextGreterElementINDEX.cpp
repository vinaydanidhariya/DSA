#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    // Your code here
    if (arr.size() == 1)
    {
        return {-1};
    }
    stack<pair<long long, int>> st;
    vector<long long> newArr(n + 1, 0);
    vector<long long> Index(n + 1, 0);

    // pair<long long, int> myPair1 = make_pair(arr[n - 1], n - 1);
    // st.push(myPair1);

    // newArr[n - 1] = -1;
    // Index[n - 1] = -1;

    for (int i = n - 1; i >= 0; i--)
    {
        pair<long long, int> topPair = st.top();

        while (st.empty() != true && arr[i] >= topPair.first)
        {
            st.pop();
        }

        if (st.empty())
        {
            newArr[i] = -1;
            Index[i] = -1;
        }
        else
        {
            pair<long long, int> topPair2 = st.top();
            newArr[i] = topPair2.first;
            Index[i] = topPair2.second;
        }
        pair<long long, int> myPair1 = make_pair(arr[i], i);
        st.push(myPair1);
    }

    for (int i = 0; i < Index.size() - 1; i++)
    {
        cout << Index[i] << "\n";
    }
    return newArr;
}

int main()
{
    vector<long long> nums = {4, 5, 2, 25};
    // 5 25 25 -1
    int n = 4;
    vector<long long> numNew = nextLargerElement(nums, n);
    for (int i = 0; i < numNew.size() - 1; i++)
    {
        cout << numNew[i] << " ";
    }

    return 0;
}