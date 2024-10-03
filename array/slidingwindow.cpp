#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int findSumOf3(vector<int> num)
{
    int k = 3;
    int sum = 0, max_sum = 0;
    for (int i = k - 1; i < num.size(); i++)
    {
        sum = num[i] + num[i - 1] + num[i - 2];
        max_sum = max(max_sum, sum);
    }
    return sum;
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
// not continue


int main()
{
    vector<int> num = {3, 7, 4, 1, 12, -4, 18};
    cout << max_sum_operation(num, 3);
    return 0;
}