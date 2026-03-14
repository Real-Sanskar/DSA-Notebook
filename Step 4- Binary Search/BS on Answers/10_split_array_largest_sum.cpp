// given an array and an integer k, split the array into k parts, such that maxSubarraySum is minimized 
// subarrays should be non-empty and contiguous 

#include<bits/stdc++.h>
using namespace std;




int checkParts(vector<int> &arr, int allowedSum){
    int sum = 0, parts = 1;
    for(int i=0; i<arr.size(); i++){
        if(sum + arr[i] <= allowedSum){
            sum += arr[i];
        }
        else{
            parts++;
            sum = arr[i];
        }
    }
    return parts;
}



// Linear Search (TC : O(sum - max) * O(N))

// check all possible maxSum from max(arr) to sum(arr)
// for each maxSum, check if split is possible 
// if yes -> return maxSum (first valid is minimum)


// int largest_sum(vector<int> &arr, int k){
//     int minVal = *max_element(arr.begin(),arr.end());
//     int maxVal = accumulate(arr.begin(),arr.end(),0);

//     for(int i=minVal; i<maxVal; i++){
//         if(checkParts(arr,i) == k){
//             return i;
//         }
//     }
//     return -1;
// }




// Binary Search (TC : O(sum - max) * O(N))

// for each mid in answer space:
// check if split is possilbe
// if yes -> store in ans -> search minimum
// else -> search larger maxSum

int largest_sum(vector<int> &arr, int k){
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    int ans = 0;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(checkParts(arr,mid) <= k){
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
    vector<int> arr = {1,2,3,4,5};
    int k = 3;

    cout << largest_sum(arr,k) << endl;

    return 0;
}