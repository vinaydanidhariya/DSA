#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> findLargestKElements(const vector<int> &arr, int k)
{
    vector<pair<int, int>> indexedArr;
    for (int i = 0; i < arr.size(); ++i)
    {
        indexedArr.push_back({arr[i], i});
    }

    sort(indexedArr.begin(), indexedArr.end(), greater<pair<int, int>>());

    vector<pair<int, int>> result;
    for (int i = 0; i < k; ++i)
    { 
        result.push_back(indexedArr[i]);
    }

    return result;
}

int max_sum_operation(vector<int> &v, int k)
{
    int sum = 0;
    int end_pos = k - 1;
    for (int i = 0; i < k; i++)
    {
        sum += v[i];
    }
    int max_sum = sum;
    for (int i = k; i < v.size(); i++)
    {
        sum += v[i];
        sum -= v[i - k];
        if (max_sum < sum)
        {
            max_sum = sum;
            end_pos = i;
        }
    }
    for (int i = end_pos - k + 1; i < end_pos; i++)
    {
        cout << i << endl;
    }

    cout << end_pos << " ";
    return sum;
}

int main()
{
    vector<int> arr = {10, 4, 3, 50, 23, 90};
    int k = 3;

    for (int k = 0; k < arr.size(); i++)
    {
        int sum = max_sum_operation()
    }

    return 0;
}
