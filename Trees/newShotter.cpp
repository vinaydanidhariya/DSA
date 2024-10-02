#include <iostream>
#include <vector>
using namespace std;

int findAlive(vector<int> nums, int start)
{
    // Base case: If only one person remains, return that person
    if (nums.size() == 1)
    {
        cout << "Last person alive: " << nums[0] << endl;
        return nums[0];
    }

    vector<int> newNums;
    
    // Loop to simulate elimination of every second person
    for (int i = start; i < nums.size(); i += 2)
    {
        newNums.push_back(nums[i]);
    }

    // Display current round of survivors
    for (int num : newNums)
        cout << num << " ";
    cout << endl;

    // Determine the starting index for the next round
    if ((nums.size() - start) % 2 == 0)
        start = 1; // if we have eliminated an even number, start from the second person
    else
        start = 0; // otherwise, start from the first person
    
    return findAlive(newNums, start);
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    findAlive(nums, 0); // Start elimination from index 0
    return 0;
}
