// Reverse a given array and return it back

#include<iostream>
using namespace std;

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// // 1. Using a new array
// void rev(int arr[], int n){
//     int ans[n];
//     for(int i=0; i<n; i++){
//         ans[i] = arr[n-1-i];
//     }
//     printArray(ans,n);
// }      

// // 2. Without new array (2 pointer approach)
// void rev(int arr[], int n){
//     int st = 0;
//     int end = n-1;
//     while(end>st){
//         swap(arr[st],arr[end]);
//         st++,end--;
//     }
//     printArray(arr,n);
// }

// 3. Recursive approach
void rev(int arr[], int st, int end){
    if(st<end){
        swap(arr[st],arr[end]);
        rev(arr, st+1, end-1);
    }
}


int main(){
    int arr[] = {1,2,3,4,5};
    int n = 5;

    // rev(arr,n);

    rev(arr, 0, n-1);
    printArray(arr,n);

    return 0;
}