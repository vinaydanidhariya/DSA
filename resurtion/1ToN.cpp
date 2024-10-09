#include <bits/stdc++.h>
using namespace std;

void PrintN(int n)
{
    if (n == 0)
    {
        return;
    }
    PrintN(n - 1);
    cout << n << " ";
}

int main()
{
    PrintN(3);
    return 0;
}