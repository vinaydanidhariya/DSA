#include <iostream>
#include <string>

using namespace std;

// Function to calculate the power of a number with modulo
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

// Function to convert a substring in base `b` to a base 10 number modulo `m`
long long solve1(const string &sub, int base, int module) {
    long long p = 0;
    long long to = 0;
    long long val = 0;
    for (long long i = sub.size() - 1; i >= 0; i--) {
        val = sub[i] - '0';
        long long power_mod = mod_exp(base, p, module);
        to = (to + (val * power_mod) % module) % module;
        p++;
    }
    return to;
}

// Function to calculate the magic number
long long get_magic_number(const string &s, int k, int b, int m) {
    long long sum = 0;
    for (size_t i = 0; i + k <= s.size(); i++) {
        string sub = s.substr(i, k);
        long long val = solve1(sub, b, m);
        sum += val % m;
    }
    return sum;
}

int main() {
    string s;
    cin >> s;
    int k, b, m;
    cin >> k >> b >> m;
    long long result = get_magic_number(s, k, b, m);
    cout << result << endl; // Print the final result
    return 0;
}
