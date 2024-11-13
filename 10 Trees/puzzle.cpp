#include <iostream>
#include <vector>
using namespace std;
int findAlive(vector<int> nums, int start)
{
    bool gunMan = true;
    int n = nums.size() - 1;
    vector<int> newNums;

    if (n == 1)
    {
        cout << nums[0];
        return nums[0];
    }

    newNums.push_back(nums[0]);
    for (int i = start; i < nums.size() ; i = i + 2)
    {
        // if (gunMan)
        // {
        // i++;
        newNums.push_back(nums[i]);
        //     gunMan = false;
        // }
        // gunMan = true;
        cout << nums[i] << " ";
    }
    cout << "\n ";
    if (newNums.size() % 2 == 0)
    {
        start = 1;
        findAlive(newNums, start);
    }
    else
    {
        start = 0;
        findAlive(newNums, start);
    }
    return 0;
}

int main()
{
    // int n;
    // cin >> n;
    // vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> nums = {1, 3, 5, 7, 9};

    findAlive(nums, 0);
    return 0;
}