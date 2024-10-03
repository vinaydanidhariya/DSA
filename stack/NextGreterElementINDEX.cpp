#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<long long> nextLargerElement(vector<long long> nums, int n)
{
    stack<int> st;
    vector<long long> Index(n, -1);

    for (int i = n - 1; i >= 0; i--)
    {
        int index = st.top();
        while (st.empty() != true && nums[i] > nums[index])
        {
            st.pop();
            index = st.top();
        }
        (!st.empty()) ? Index[i] = st.top() : Index[i] = -1;
        st.push(i);
    }
    cout << "\n";
    return Index;
}

int main()
{
    vector<long long> nums = {4, 5, 2, 25};
    // 5 25 25 -1

    int n = 4;
    vector<long long> index = nextLargerElement(nums, n);
    for (int i = 0; i < index.size(); i++)
    {
        cout << ((index[i] == -1) ? -1 : nums[index[i]]) << " ";
        cout << index[i] << " " << "\n";
    }

    return 0;
}