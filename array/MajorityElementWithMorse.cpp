#include <iostream>
#include <vector>
#include <map>
#define vii vector<int, int>
using namespace std;

int MajorityElementWithMorse(vector<int> v)
{
    int votes = 0, leadingEle = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (!votes)
        {
            votes = 1;
            leadingEle = nums[i];
        }
        else
        {
            votes = (nums[i] == leadingEle) ? votes + 1 : votes - 1;
        }
    }

    int countMajor = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == leadingEle)
        {
            countMajor++;
            if (countMajor > nums.size() / 2)
            {
                return leadingEle;
            }
        }
    }
    return -1;
    
}

// vector<int> twoSum(vector<int> &nums, int target)
// {
//     for (int i = 0; i <= nums; i++)
//     {
//     }
// }

int main()
{
    vector<int> v1 = {3, 2, 3};
    int k = 2;
    cout << MajorityElementWithMorse(v1) << "----------------";

    return 0;
}