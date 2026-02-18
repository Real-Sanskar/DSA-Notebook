// Given an array of integers, every element occur twice except one
// Find the single number in array

#include<iostream>
#include<vector>
using namespace std;

// int single_element(vector<int> &arr){
//     int n = arr.size();
    
//     if(n == 1){
//         return arr[0];
//     }

//     for(int i=0; i<n; i++){
//         if(i == 0 && arr[i] != arr[i+1]){
//             return arr[i];
//         }
//         if(i == n-1 && arr[i-1] != arr[i]){
//             return arr[i];
//         }

//         if(arr[i] != arr[i-1]  && arr[i] != arr[i+1]){
//             return arr[i];
//         }
//     }
// }


// int single_element(vector<int> &arr){
//     int n = arr.size();
//     int ans = 0;

//     for(int i=0; i<n; i++){
//         ans = ans ^ arr[i];
//     }
//     return ans;
// }







// Binary search    (TC : O(logN)    SC : O(1))

// **Key Observation:**

// **Before single element:**
// - Pairs start at EVEN index: (0,1), (2,3), (4,5)...
// - Pattern: arr[even] == arr[even+1]

// **After single element:**
// - Pairs start at ODD index: (1,2), (3,4), (5,6)...
// - Pattern: arr[even] != arr[even+1]



// Handle edge cases (first/last element)
// Binary search on (1,n-2):
// calculate mid = (low+high)/2
// if mid is single element -> return arr[mid]

// if mid is EVEN AND a[m] == a[m+1] OR mid is ODD AND a[m] == a[m-1] -> search right
// else -> search left


int single_element(vector<int> &arr){
    int n = arr.size();
    int low = 1, high = n-1;

    if(n == 1){
        return arr[0];
    }
    if(arr[0] != arr[1]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];

    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]){
            return arr[mid];
        }

        if((mid%2 == 1 && arr[mid] == arr[mid-1]) || (mid%2 == 0 && arr[mid] == arr[mid+1])){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}



int main(){
    vector<int> arr = {1,1,2,2,3,3,4,5,5,6,6};

    cout << single_element(arr) << endl;

    return 0;
}