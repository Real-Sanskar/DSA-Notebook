//Given an array and a target, find smallest index where [element >=  target]
#include<iostream>
#include<vector>
using namespace std;


// 1. Brute force (Linear Seach)   (TC :O(N)   SC : O(1))

// 1. traverse from left to right
// 2. return first index where, arr[i] >= target
// 3. if not found return, size of array (n)

// int lower_bound(vector<int> arr, int x){
//     int n = arr.size();

//     for(int i=0; i<n; i++){
//         if(arr[i] >= x){
//             return i;
//         }
//     }
//     return n;
// }





// 2. Optimal approach (Binary Search)   (TC : O(logN)  SC : O(1))

// 1. initialize low and high pointer
// 2. Iterate while(low <= high)
//      if arr[mid] >= target
//          ans = mid   (POSSIBLE ANSWER)
//          Search left : high = mid - 1
//      else Search right : low = mid + 1
// return ans


int lower_bound(vector<int> &arr, int x){
    int n = arr.size();
    int low = 0, high = n-1;
    int minIdx = -1;

    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] >= x){
            minIdx = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    if(minIdx != -1){
        return minIdx;
    }
    else{
        return n;
    }
}

int main(){
    vector<int> arr = {3,5,8,15,19};
    int x = 9;

    cout << lower_bound(arr,x) << endl;

    return 0;
}