#include <iostream>
#include <numeric>

using namespace std;

int midian(vector v)
{
    vector<int> midian(v.size());
    int sum = accumulate(v.begin(), v.end(), 0);
    cout<<sum;
    for (int i = 0; i < v.size(); i++)
    {
        /* code */
    }

    return 0;
}

int main()
{

    vector<int> v = {1, 2, 3, 5, 6, 7, 8, 9, 10};
    cout << midian(v);
    return 0;
}