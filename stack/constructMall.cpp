#include <bits/stdc++.h>
using namespace std;

int constructMall2(vector<int> &heights)
{
    stack<int> st;
    int n = heights.size();
    vector<int> PSI(n, -1), NSI(n, n);
    // next smaller element
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] > heights[i])
        {
            NSI[st.top()] = i;
            st.pop();
        }
        if (!st.empty())
        {
            NSI[st.top()] = heights.size();
        }
        st.push(i);
    }

    while (!st.empty())
    {
        st.pop();
    }
    // previous smaller element
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] > heights[i])
        {
            PSI[st.top()] = i;
            st.pop();
        }
        if (!st.empty())
        {
            PSI[st.top()] = -1;
        }
        st.push(i);
    }

    for (int i = 0; i < PSI.size(); i++)
    {
        cout << PSI[i] << " ";
    }
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "\n ";
        int RD = NSI[i] - i - 1;
        int LD = i - PSI[i] - 1;
        cout << NSI[i] << " NSI ";
        cout << PSI[i] << " PSI ";

        cout << RD << " RD";
        cout << LD << " LD";
        cout << "\n";
        ans = max(ans, (RD + LD + 1) * heights[i]);
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
            cout << "+++" << ans << endl;
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
            cout << "--" << ans << endl;
        }
        else
        {
            break;
        }
    }

    return ans * count;
}

int main()
{
    vector<int> heights = {4, 3, 2, 5, 4, 1, 4, 5};
    // vector<int> heights = {2,1,5,6,2,3};
    cout << constructMall2(heights) << endl;
    return 0;
}