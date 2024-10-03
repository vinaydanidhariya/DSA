#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> nums, int target)
{
    int n = nums.size();
    int sum;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            sum = nums[i] + nums[j];
            if (sum == target)
            {
                cout << nums[i] << nums[j];
                return {i, j};
            }
        }
    }
    return {-1};
}

int main()
{
    vector<int> nums = {2, 11, 7, 15};
    int target = 9;
    twoSum(nums, target);
    return 0;
}