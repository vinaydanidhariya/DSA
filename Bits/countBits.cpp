#include <bits/stdc++.h>
using namespace std;
int countBits(int n){
    int count=0;
    // while(n){
    //     count++;
    //     n>>=1;
    // }

    // log
    // return count;
    return ceil(log2(n));
}
int main(){
    cout<<countBits(5);
    cout<<"\n";
}