//Given an arrray and a target, find smallest index where [element > target]
#include<iostream>
#include<vector>
using namespace std;



// 1. Brute force (Linear Search)   (TC : O(N)   SC : O(1))

// 1. Traverse array from left to right
// 2. return first index where, arr[i] > target
// 3. if not found, return size of array (n)

// int upper_bound(vector<int> &arr, int target){
//     int n = arr.size();

//     for(int i=0; i<n; i++){
//         if(arr[i] > target){
//             return i;
//         }
//     }
//     return n;
// }




// 2. Optimal approach (Binary Search)  (TC : O(logN)    SC : O(1))

// 1. Initialize pointer : low, high
// 2. Traverse array while (low <= high)
//       calculate mid 
//       if(arr[mid] > target)
//          ans = mid (POSSIBLE ANSWER)
//          search left : high = mid - 1
//      else search right : low = mid + 1
//   return ans   

int upper_bound(vector<int> &arr, int target){
    int n = arr.size();

    int low = 0, high = n-1, ans = n;
    while(low <= high){
        int mid = low + (high - low)/2;

        if(arr[mid] > target){
            ans = mid ;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return ans;
}

int main(){
    vector<int> arr = {3,5,8,9,15,19};
    int target = 9;

    cout << upper_bound(arr,target) << endl;

    return 0;
}