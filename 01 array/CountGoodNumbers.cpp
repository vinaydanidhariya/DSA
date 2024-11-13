#include <iostream>
#include <vector>

using namespace std;


int countGoodNumbers(long long n) {
    long long mod = 1000000007;
    long long result = 1;
    long long odd = n/2;
    long long even = n/2;
    if (n%2 != 0) {
        odd++;
    }
    for (int i=0; i<odd; i++) {
        result = (result*5)%mod;
    }
    for (int i=0; i<even; i++) {
        result = (result*4)%mod;
    }
    return result;
}

int main() {
    long long n = 50;
    cout << countGoodNumbers(n) << endl;
    return 0;
}