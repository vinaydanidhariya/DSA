#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> nums, int target)
{
    // Brute force approach  n^2
    // for (int  i = 0; i < nums.size(); i++)
    // {
    //     for (int j = i+1; j < nums.size(); j++)
    //     {
    //         if (nums[i]+nums[j]==target)
    //         {
    //             return {i,j};
    //         }

    //     }
    // }

    // better approach
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        if (m.find(target - nums[i]) != m.end())
        {
            int index = m[target - nums[i]];
            return {index, i};
        }
        else
        {
            m[nums[i]] = i;
        }
    }

    return {-1};
}

int main()
{
    vector<int> nums = {2, 11, 7, 15};
    int target = 9;
    vector<int> res = twoSum(nums, target);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
    }

    return 0;
}