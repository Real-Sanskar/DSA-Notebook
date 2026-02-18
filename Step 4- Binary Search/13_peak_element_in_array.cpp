// Given an array, find index of peak element
// Note: If multiple peaks present, return any 

#include<iostream>
#include<vector>
using namespace std;



// 1. Brute force (Linear search)  (TC : O(N))

// Handle edge cases (first and last element)
// For each middle element check if arr[i] > arr[i-1] && arr[i] > arr[i+1]

// int peak_element(vector<int> &arr){
//     int n = arr.size();

//     for(int i=0; i<n; i++){
//         bool left = (i==0) || (arr[i] >= arr[i-1]);
//         bool right = (i==n-1) || (arr[i] >= arr[i+1]);

//         if(left && right) return i;
//     }
//     return -1;
// }





// Binary search (TC : O(logN))

// Key Observation:

// If arr[mid] > arr[mid-1] and arr[mid] > arr[mid+1] → peak found
// If arr[mid] < arr[mid+1] → peak exists on RIGHT (ascending slope)
// If arr[mid] < arr[mid-1] → peak exists on LEFT (descending slope)

// Why it works?

// If slope going up to right → there must be a peak on right side
// If slope going up to left → there must be a peak on left side
// Always converges to a peak

// Algorithm:

// Handle edge cases
// Binary search in (1, n-2):

// If arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]: return mid
// If arr[mid] < arr[mid+1]: low = mid + 1 (go right)
// Else: high = mid - 1 (go left)

int peak_element(vector<int> &arr){
    int n = arr.size();


    // Edge cases
    if(n == 1) return 0;
    if(arr[0] > arr[1]) return 0;
    if(arr[n-1] > arr[n-2]) return n-1;

    int low = 1, high = n-2;
    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
            return mid;
        }
        else if(arr[mid] < arr[mid+1]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,5,1};

    cout << peak_element(arr) << endl;

    return 0;
}