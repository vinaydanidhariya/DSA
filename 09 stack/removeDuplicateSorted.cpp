#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    if (nums.size() == 0 || nums.size() == 1)
    {
        return nums.size();
    }
    int curr = 0;
    int next = 1;
    int count = 0;
    for (int i = 0; i < nums.size() && next < nums.size(); i++)
    {
        while (nums[curr] == nums[next])
        {
            next++;
        }
        count++;
        nums[i + 1] = nums[next];
        curr = next;
        next++;
    }
    return count + 1;
}
int main()
{
    // vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    vector<int> nums = {1, 2};

    int res = removeDuplicates(nums);
    cout << "\n prg Output";
    for (int i = 0; i < res; i++)
    {
        cout << " " << nums[i];
    }
}
