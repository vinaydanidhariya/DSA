#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<long long> nextLargerElement(vector<long long> nums, int n)
{
    stack<int> st;
    vector<long long> NGE(n, -1);
    // n^2
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     for (int j = i + 1; j < nums.size(); j++)
    //     {
    //         if (nums[i] < nums[j])
    //         {
    //             Index[i] = j;
    //             break;
    //         }
    //     }
    // }

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && nums[st.top()] < nums[i])
        {
            // for element 
            NGE[st.top()] = nums[i];
            // for index
            // NGE[st.top()] = i;
            st.pop();
        }
        if (!st.empty())
        {
            NGE[st.top()] = -1;
        }
        st.push(i);
    }
    cout << "\n";
    return NGE;
}

int main()
{
    vector<long long> nums = {4, 5, 2, 25};
    // 5 25 25 -1

    int n = 4;
    vector<long long> index = nextLargerElement(nums, n);
    for (int i = 0; i < index.size(); i++)
    {
        // cout << ((index[i] == -1) ? -1 : nums[index[i]]) << " ";
        cout << index[i] << " " << "\n";
    }

    return 0;
}