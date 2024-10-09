#include <bits/stdc++.h>

using namespace std;

stack<int> monotonicIncrease(vector<int> &nums)
{
    stack<int> st;
    for (int i = 0; i < nums.size(); i++)
    {
        while (!st.empty() && st.top() >= nums[i])
        {
            st.pop();
        }
        st.push(nums[i]);
    }
    return st;
}

stack<int> monotonicDecrease(vector<int> &nums)
{
    stack<int> st;
    for (int i = 0; i < nums.size(); i++)
    {
        while (!st.empty() && st.top() <= nums[i])
        {
            st.pop();
        }
        st.push(nums[i]);
    }
    return st;
}

int main()
{
    vector<int> nums = {1, 7, 9, 5, 8};
    stack<int> sI = monotonicIncrease(nums);
    stack<int> sD = monotonicDecrease(nums);
    while (!sI.empty())
    {
        int ele = sI.top();
        cout << ele << " ";
        sI.pop();
    }
    cout << endl;
    while (!sD.empty())
    {
        int ele = sD.top();
        cout << ele << " ";
        sD.pop();
    }
    cout<<endl;
    return 0;
}