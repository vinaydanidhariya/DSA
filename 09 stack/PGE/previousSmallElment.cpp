#include <bits/stdc++.h>
using namespace std;
vector<int> NextSmallerElement(vector<int> &nums)
{
    stack<int> st;
    vector<int> nsi(nums.size(), -1);
    for (int i = 0; i < nums.size(); i++)
    {
        while (!st.empty() && nums[i] >= nums[st.top()])
        {
            st.pop();
        }
        if (!st.empty() && nums[i] < nums[st.top()])
        {
            nsi[i] = nums[i];
        }
        st.push(nums[i]);
    }
    return nsi;
}
int main()
{
    vector<int> nums = {4, 3, 2, 5, 4, 1, 4, 5};
    vector<int> NSI = NextSmallerElement(nums);
    for (int i = 0; i < NSI.size(); i++)
    {
        cout << NSI[i]<<" ";
    }
    cout << "hello" << endl;
}