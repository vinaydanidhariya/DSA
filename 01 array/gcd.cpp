#include <vector>
#include <iostream>
#include <climits>

using namespace std;

int GCD(int a, int b){
    if(b==0){
        return a;
    }
    return GCD(b,a%b);
}

int findGCD(vector<int>& nums) {
        int min = INT_MAX;
        int max = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<min){
                min = nums[i];
            }
            if(nums[i]>max){
                max = nums[i];
            }
        }
        if(min==0){
            return max;
        }
        
        return GCD(min,max);
    }


int main() {
    vector<int> v = {2, 4, 6, 8, 10};
    cout << findGCD(v) << endl;
    return 0;
}