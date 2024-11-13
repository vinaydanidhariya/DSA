#include <iostream>
#include <vector>

using namespace std;

// binary search using recursion

int binary_search(vector<int> v, int target, int start, int end) {
    if (start >= end) {
        return -1;
    }
    int mid = start + (end - start) / 2;
    if (v[mid] == target) {
        return mid;
    }
    if (v[mid] < target) {
        return binary_search(v, target, mid + 1, end);
    }
    return binary_search(v, target, start, mid - 1);
}


// find square root of a number using binary search
float square_root(int n, float start, float end) {

    float mid = start + (end - start) / 2;
    if (mid * mid == n || abs(mid * mid - n) < 0.00001) {
        return mid;
    }
    if (mid * mid < n) {
        return square_root(n, mid, end);
    }
    return square_root(n, start, mid);
}
// Rahul@411425

// Divyesh@411425


// find square root of a number using proximity standard deviation recursion



// eculudian gcd using recursion
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}


// power of a number using recursion
int power(int a, int b) {
    if (b == 0) {
        return 1;
    }
    return a * power(a, b - 1);
}






int main() {
    // vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // cout << binary_search(v, 5, 0, v.size() - 1) << endl;
    // int num ;
    // cin >> num;
    // cout << square_root(25, 0, 25) << endl;
    cout << gcd(10, 15) << endl;
    return 0;
}