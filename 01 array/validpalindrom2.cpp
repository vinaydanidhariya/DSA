#include <iostream>
#include <vector>
using namespace std;

// using recursion 
bool isPalindrome(string s,int left,int right){
    while(left<right){
        if(s[left]!=s[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// using two pointer recursion
bool validPalindrome(string s) {
    int left = 0;
    int right = s.size()-1;
    while(left<right){
        if(s[left]!=s[right]){
            return isPalindrome(s,left+1,right) || isPalindrome(s,left,right-1);
        }
        left++;
        right--;
    }
    return true;
}
// time complexity is O(n) and space complexity is O(1) with k=1 

int main(){
    string s = "abca";
    cout<<validPalindrome(s);
    return 0;
}