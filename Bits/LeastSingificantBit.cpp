#include <bits/stdc++.h>
using namespace std;

int lsb(int n){ 
    return n & -n;    
}

int main(){
    cout<<lsb(4);
    cout<<"\n";
}