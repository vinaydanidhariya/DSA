#include <iostream>
#include <cmath>
using namespace std;

int binaryToDecimal(int bin) {
    int dec = 0;
    int i = 0;
    while (bin != 0) {
        int rem = bin % 10;
        dec += rem * pow(2, i);
        bin /= 10;
        i++;
    }
    return dec;
}

int main() {
    int bin = 1001001; // binary number
    int dec = binaryToDecimal(bin);
    std::cout << "Decimal equivalent: " << dec << std::endl;
    return 0;
}