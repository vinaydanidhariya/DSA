#include <iostream>
#include <vector>
using namespace std;


void mergeSort(vector<int>& nums)
{
    int n = nums.size();
    if (n <= 1)
        return;

    vector<int> left, right;
    for (int i = 0; i < n / 2; i++)
        left.push_back(nums[i]);
    for (int i = n / 2; i < n; i++)
        right.push_back(nums[i]);

    mergeSort(left);
    mergeSort(right);

    int i = 0, j = 0;
    for (int k = 0; k < n; k++)
    {
        if (j >= right.size() || i < left.size() && left[i] <= right[j])
        {
            nums[k] = left[i];
            i++;
        }
        else
        {
            nums[k] = right[j];
            j++;
        }
    }
}

void printVector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << " " << v[i];
    }
    cout << endl;
}

int main()
{
    vector<int> nums = {5, 6, 9, 7, 8, 2, 5, 5};
    cout << "Original Array \n";
    printVector(nums);
    mergeSort(nums);
    cout << "\nMerge Sorted Array : \n";
    printVector(nums);
}