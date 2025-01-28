#include <bits/stdc++.h>
using namespace std;

int msb(int n){
 int count=-1;
    while(n){
        count++;
        n>>=1;
    }
    return count;
}

int main(){
    cout<<msb(5);
    cout<<"\n";
}