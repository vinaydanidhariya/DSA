#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// note time complexity of quick sort is O(nlogn) and space complexity is O(logn) 
// how much time it will take to sort 10^6 elements
// 10^6 * log(10^6) = 10^6 * 20 = 2 * 10^7
// 2 * 10^7 = 2 * 10^7 / 10^6 = 2 * 10 = 20 seconds


int main()
{
    vector<int> v = {1, 5, 3, 2, 8, 7, 6, 4};
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
    return 0;
}