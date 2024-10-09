
#include <iostream>
#include <vector>

using namespace std;

    bool isPowerOfThree(int n) {
        if (n==1)
        {
        return false;
        }
        while(n>1)
        {
            if(n%3!=0)
            {
                return false;
            }
            n=n/3;
        }
        return true;
    }
    bool isPowerOfThree(long long n) {
        if (n == 1) {
            return true;
        }
        if (n>-1 && n<3)
        {
            return false;
        }
        if (n % 3 != 0) {
            return false;
        }
        return isPowerOfThree(n/3);
    }

    // using log
    bool isPowerOfThree(int n) {
        if (n == 1) {
            return true;
        }
        if (n == 0) {
            return false;
        }
        return (log10(n) / log10(3)) == int(log10(n) / log10(3));
    }
    // using max power of 3
    bool isPowerOfThree(int n) {
        int biggestPowerOfThree = 1162261467;
        return n > 0 && biggestPowerOfThree % n == 0;

    }
int main() {
    long long n = 50;
    cout << isPowerOfThree(n) << endl;
    return 0;
}
