#include<iostream>
#include<vector>
using namespace std;

// // 1. Brute force approach
// // TC : O(N*N)  SC : O(1)

// bool check_sorted(vector<int> arr, int n){

//     for(int i = 0; i<n-1; i++){
//         for(int j = i+1; j<n; j++){
//             if(arr[i] > arr[j]){
//                 return false;
//             }
//         }
//         return true;
//     }
    
// }

// 2. Optimal approach (single traversal)
// TC : O(N)  SC : O(1)

bool check_sorted(vector<int> arr, int n){
    for(int i=0; i<n-1; i++){
        if(arr[i] > arr[i+1]){
            return false;
        }
    }
    return true;
    
}


int main(){
    vector<int> arr = {1,2,3,4,5};
    int n = arr.size();

    if(check_sorted(arr,n)){
        cout << "Array is sorted" << endl;
    }
    else{
        cout << "Array is not sorted" << endl;
    }

    return 0;
}