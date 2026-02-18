// Find index of target element in sorted array

#include<iostream>
#include<vector>
using namespace std;



// 1. Iterative approach (TC: O(logN)    SC : O(1))

// use low and high pointer
// loop while (low <=high)
// computer mid and compare arr[mid] with target : 
//      -> if equal -> return index
//      -> if target < arr[mid]  -> move high = mid-1
//      -> else -> move low = mid+1

// int binary_search(vector<int> arr, int target){
//     int n = arr.size();

//     int low = 0, high = n-1;

//     while(low <= high){
//         int mid = low + (high-low)/2;

//         if(arr[mid] == target) return mid;
//         else if(arr[mid] > target){
//             high = mid-1;
//         }
//         else{
//             low = mid+1;
//         }
//     }
//     return -1;
// }




// 2. Recursive approach : (TC: O(logN)   SC:O(1))

// base case : if(low > high) return -1
// compute mid and compare arr[mid] with target :
//      -> if equal -> return mid
//      -> if target < arr[mid] -> recurse left half
//      -> else -> recurse right half

int binary_search(vector<int> arr, int target, int low, int high){
    if(low < high){
        int mid = low + (high-low)/2;
        if(arr[mid] == target) return mid;

        else if(arr[mid] > target) return binary_search(arr,target,low,mid-1);

        else return binary_search(arr,target,mid+1,high);
    }
    return -1;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    int target = 8;
    int n = arr.size();

    // cout << binary_search(arr,target) << endl;

    cout << binary_search(arr,target,0,n-1) << endl;

    return 0;
}