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

string DecimalToBinary(int n) {
    string s = "";
    // while (dec != 0) {
    //     int rem = dec % 2;
    //     bin = to_string(rem) + bin;
    //     dec /= 2;
    // }
    while(n){
        s +=  to_string(n&1)+s;
    }
    return s;
}
// flip ith bit 
int flip(int n, int i){
    return n^(1<<i);
}

// delete i th bit
// int del(int n, int i){
//     return n&(~(1<<i));
// }
int del(int n, int i){
    return n | (1<<i);
}


// del lsb bit
int lsb(int n){ 
    return n & -n;    
}

// int lsbDel(int n){
//     return n & (n-1);
// }




// power of 2
bool isPowerOfTwo(int n){
    return n && !(n & (n-1));
}

// loop through all the set bits
vector<int> setBits(int n){
    vector<int> v;
    for(int i=0; i<32; i++){
        if(n & (1<<i)){
            v.push_back(i);
        }
    }
    return v;
}


int main() {
    int bin = 1001001; // binary number
    int dec = binaryToDecimal(bin);
    cout << "Decimal equivalent: " << dec << endl;
    cout << "Binary equivalent: " << DecimalToBinary(dec) << endl;
    return 0;
}