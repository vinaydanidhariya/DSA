#include <iostream>
#include <vector>

using namespace std;
// 5 1
// 4 2 3 5 1

vector<int> largestPermutation(int k, vector<int> arr) {
        
        int max = arr.size();
        cout << max << endl;
        
        for (int i=0; i<arr.size(); i++) {
            if (arr[i] == max) {
                swap(arr[i], arr[max-1]);
            }
        }

        return arr;
}

int main() {
    vector<int> arr = {4, 2, 3, 5, 1};
    int k = 1;
    vector<int> result = largestPermutation(k, arr);
    for (int i=0; i<result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}   