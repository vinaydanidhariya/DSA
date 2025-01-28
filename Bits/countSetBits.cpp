#include <bits/stdc++.h>
using namespace std;
int countSetBits(int n){
 int count=0;
    while(n){
        count++;
        n>>=1;  
    }
}
int main(){
    cout<<countSetBits(5);
    cout<<"\n";
}