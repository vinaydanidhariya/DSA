#include <iostream>
#include <vector>

using namespace std;

int superDigit(string n, int k) {
    long long sum = 0;
    for (char c : n) {
        sum += c - '0';
    }
    cout << sum << endl;
    sum *= k;
    string sumStr = to_string(sum);
    if (sumStr.size() == 1) {
        return sum;
    }
    return superDigit(sumStr, 1);
}

int main() {
    string n = "9875";
    int k = 4;
    cout << superDigit(n, k) << endl;
    return 0;
}