#include <bits/stdc++.h>
using namespace std;

vector<int> prefixSum(vector<int> &nums)
{
    vector<int> prefix(nums.size());
    prefix[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        prefix[i] = prefix[i - 1] + nums[i];
    }
    return prefix;
}

vector<int> postfixSum(vector<int> &nums)
{
    vector<int> postfix(nums.size());
    postfix[nums.size() - 1] = postfix[nums.size() - 1];
    for (int i = nums.size()-1; i >= 0; i--)
    {
        postfix[i] = postfix[i+1] + nums[i];
        
    }
    return postfix;
}

int main()
{
    int n;
    cin >> n;
    int num;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        // https://ocw.mit.edu/courses/6-042j-mathematics-for-computer-science-fall-2010/93cad640cf3ed0b23ef70688f452d4d5_MIT6_042JF10_notes.pdf
        nums.push_back(num);
    }
    vector<int> prefix = prefixSum(nums);
    vector<int> postfix = postfixSum(nums);
    for (int i = 0; i < prefix.size(); i++)
    {
        cout << prefix[i] << " ";
        cout << postfix[i] << " ";
        cout << "\n";
    }
}