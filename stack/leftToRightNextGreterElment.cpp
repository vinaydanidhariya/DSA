#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<long long> nextLargerElement(vector<long long> nums, int n)
{
    stack<long long> st;
    vector<long long> ans(n, -1);
    for (int i = 0; i < nums.size(); i++)
    {
        while (!st.empty() && nums[i] > nums[st.top()])
        {
            ans[st.top()] = nums[i];
            st.pop();
        }
        if (!st.empty())
        {
            ans[st.top()] = -1;
        }
        st.push(i);
    }
    return ans;
}

int main()
{
    vector<long long> nums = {1, 3, 2, 4};
    // 3 4 4 -1
    int n = 4;
    vector<long long> numNew = nextLargerElement(nums, n);
    for (int i = 0; i < numNew.size(); i++)
    {
        cout << numNew[i];
    }
    cout<<"\n";
    return 0;
}