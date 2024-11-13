#include <bits/stdc++.h>
using namespace std;

void print2(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}

void print3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

void print4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}

void print5(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= i; j--)
        {
            cout << "*" << " ";
        }
        cout << "\n";
    }
}

void print6(int n)
{
    for (int i = 1; i <= n; i++)
    {
        int num = 0;
        for (int j = n; j >= i; j--)
        {

            cout << ++num << " ";
        }
        cout << "\n";
    }
}

int main()
{
    print6(3);
}