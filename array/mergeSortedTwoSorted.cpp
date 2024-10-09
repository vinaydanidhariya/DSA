#include <iostream>
#include <vector>
using namespace std;

// void mergeArr(vector<int> a,vector<int> b, vector<int> &c){
//     int i = 0, j = 0;
//     while(i < a.size() && j < b.size()){
//         if(a[i] < b[j]){
//             c.push_back(a[i]);
//             i++;
//         }else{
//             c.push_back(b[j]);
//             j++;
//         }
//     }
//     while(i < a.size()){
//         c.push_back(a[i]);
//         i++;
//     }
//     while(j < b.size()){
//         c.push_back(b[j]);
//         j++;
//     }
//     for(int i = 0; i < c.size(); i++){
//         cout << c[i] << " ";
//     }
//     cout << endl;
// }


void mergeArr(vector<int> &arr, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    for(int i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
    }
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(vector<int> &arr, int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);
        mergeArr(arr, l, m, r);
    }

}


int main(){
    // vector<int> a = {1, 3, 5, 7, 9};
    // vector<int> b = {2, 4, 6, 8, 10};
    // vector<int> c;
    // mergeArr(a, b, c);
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    MergeSort(arr, 0, arr.size() - 1);
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    return 0;
}