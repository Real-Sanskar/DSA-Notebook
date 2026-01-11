// Given a rotated sorted array (distinct values) and a target k, find index of target
// If not found return -1


// Key Insight:

// Array has two sorted parts (before and after rotation point)
// At any mid, at least ONE half is always sorted
// Identify sorted half, check if target lies in it

#include<iostream>
#include<vector>
using namespace std;


// Rotated Binary Search Approach (TC : O(logN)   SC : O(1))

// initialize low and high pointer
// iterate while (low <= high)
// calculate mid
// if (a[mid] == target), return ans

// if (left half sorted): check
//      if target is in left half -> discard right
//      else -> discard left
// else if (right half sorted): check
//      if target is in right -> discard left
//      else -> discard right

int rotated_sorted(vector<int> &arr, int k){
    int n = arr.size();
    int idx = -1;
    int low = 0, high = n-1;

    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[mid] == k){
            idx = mid;
        }
        if(arr[low] <= arr[mid]){
            if(arr[low] <= k && k <= arr[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if(arr[mid] <= k && k <= arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return idx;
}

int main(){
    vector<int> arr = {4,5,6,7,0,1,2};
    int k = 0;

    cout << rotated_sorted(arr,k) << endl;

    return 0;
}