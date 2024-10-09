#include <iostream>
#include <vector>
using namespace std;


void MergeArr(vector<int> &arr,int left,int right,int mid){
//   in place
    int n1 = mid-left+1;
    int n2 = right-mid;
    vector<int> L(n1);
    vector<int> R(n2);
    for(int i=0;i<n1;i++){
        L[i]=arr[left+i];
    }
    for(int i=0;i<n2;i++){
        R[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=left;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }

}

void MergeSort(vector<int> &arr,int left,int right){
    // Divide code
    if(left>=right){
        return;
    }

    int mid = left + (right - left) / 2;
    
    MergeSort(arr,left,mid);
    MergeSort(arr,mid+1,right);
    // merge Code
    MergeArr(arr,left,right,mid);
    
}


int main(){
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    MergeSort(arr, 0, arr.size() - 1);


    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    return 0;
}