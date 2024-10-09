#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

//2) convert base b to 10
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

long long solve1(string sub, int base, int module) {
    long long p = 0;
    long long to = 0;
    long long val = 0;
    for (long long i = sub.size() - 1; i >= 0; i--) {
        val = sub[i] - '0';
        long long power_mod = mod_exp(base, p, module);
        to = (to + (val * power_mod) % module) % module;
        // cout << power_mod << " p : " << p << "-----------\n";
        p++;
    }
    // cout << to;
    return to;
}

//1) split into part k size part
long long solve(string &s, int k, int base, int module)
{
    long long sum = 0;
    for (int i = 0; i+k <= s.size(); i++)
    {
        // if(){ break;}
        string sub = s.substr(i, k);
        // cout<<"\n sub "<<sub<<"\n";
        long long val = solve1(sub, base,module);
        // 3)  module with m
        sum += val % module;
        
    }
    
    return sum;
}

int main()
{
    string s = "12212";
    cout<<s.size();
    int k = 99993;
    int base = 4;
    int  module = 1;
    // string s="12212";
    // int k = 3;
    // int base = 3;
    // int  module = 5;
    int total = solve(s, k, base, module);
    // long long total = solve1("1101",base);

    cout << "output is :" << total;
}