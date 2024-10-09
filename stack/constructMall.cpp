#include <bits/stdc++.h>
using namespace std;

int constructMall2(vector<int> &heights)
{
    stack<int> st;
    int n = heights.size();
    vector<int> left(n, -1), right(n, n);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            left[i] = st.top();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        st.pop();
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            right[i] = st.top();
        }
        st.push(i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, heights[i] * (right[i] - left[i] - 1));
    }
    return ans;
}




int constructMall1(vector<int> &heights, int position)
{
    // stack<int> st;
    int posVal = heights[position];
    int ans = posVal;
    int count = 1;
    int n = heights.size();
    
    for (int i = position + 1; i < n; i++)
    {
        if (heights[i] >= posVal)
        {
            count++;
            cout<<"+++"<<ans<<endl;
        }
        else
        {
            break;
        }
    }

    for (int i = position - 1; i >= 0; i--)
    {
        if (heights[i] >= posVal)
        {
            count++;
            cout<<"--"<<ans<<endl;
        }
        else
        {
            break;
        }
    }

    return ans*count;
}

int main()
{
    // vector<int> heights = {4, 3, 2, 5, 4, 1, 4, 5};
    vector<int> heights = {2,1,5,6,2,3};
    cout << constructMall1(heights, 1) << endl;
    return 0;
}