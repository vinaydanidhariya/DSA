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
    stack<long long> st;
    vector<long long> newArr(n + 1, 0);

    st.push(arr[n - 1]);
    newArr[n - 1] = -1;

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < st.top())
        {
            newArr[i] = st.top();
        }
        else if (arr[i] > st.top())
        {
            while (st.empty() != true && arr[i] >= st.top())
            {
                st.pop();
            }
            if (st.empty())
            {
                newArr[i] = -1;
            }
            else
            {
                newArr[i] = st.top();
            }
        }
        st.push(arr[i]);
    }

    return newArr;
}

int main()
{
    vector<long long> nums = {1, 3, 2, 4};
    int n = 4;
    vector<long long> numNew = nextLargerElement(nums, n);
    for (int i = 0; i < numNew.size() - 1; i++)
    {
        cout << numNew[i];
    }

    return 0;
}