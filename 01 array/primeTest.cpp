#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool checkPrime(int num)
{
    for (int i = 2; i < sqrt(num); i++)
    {
        if (num == 2)
        {
            return true;
        }

        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}
int countPrimes(int n) {
        int count=0;
        for(int i=2;i<n;i++){
            if(checkPrime(n)){
                count++;
            }
        }
        return count;
    }
int main()
{
    cout << countPrimes(10);
    return 0;
}