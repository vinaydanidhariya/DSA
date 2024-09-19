#include <iostream>
#include <vector>
using namespace std;
int fact(int n)
{
    if (n > 0)
    {
        return n * fact(n - 1);
    }
    else
    {
        return 1;
    }
}
// int sumOfn()

void oneTon(int n, int original)
{
    if (n == 1)
    {
        cout << n;
        return;
    }
    oneTon(n - 1, original);
    cout << "-";
    cout << n;
    if (original == n)
    {
        cout << "*\n";
    }
}

void rev_oneTon(int n, int original)
{
    if (n == 1)
    {
        cout << n;
        return;
    }
    cout << n << "-";
    rev_oneTon(n - 1, original);
    if (original == n)
    {
        cout << "*\n";
    }
}

int fib_n(int n)
{

    if (n < 2)
    {
        return n;
    }
    cout << n << "-";
    return fib_n(n - 1) + fib_n(n - 2);
}

int fibonacci_series(int n)
{
    int pre = 0;
    int curr = 1;
}

int main()
{
    // cout << fact(6);
    // rev_oneTon(10, 10);
    cout << fib_n(10   ) << " -----------\n";
    return 0;
}