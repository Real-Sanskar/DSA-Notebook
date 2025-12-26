// given an array and a target, find the index of last occurrence of the element in the array
// if the element is not found, return -1

#include<iostream>
#include<vector>
using namespace std;



// 1. Brute force (Linear search (reverse)) (TC : O(N)   SC : O(1))

// traverse from end to start
// return index when target is found

int last_occurrence(vector<int> &arr, int target){
    int n = arr.size();

    for(int i=n-1; i>=0; i--){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

// Binary Search (TC : O(log N)   SC :O(1))

// intitalize low and high pointers
// initialize idx = -1
// iterate while(low <= high)
// if (arr[mid] == target) -> possible index -> search right
// else if(arr[mid] < target) -> search right
// else -> search left

// int last_occurrence(vector<int> &arr, int target){
//     int n = arr.size();
//     int low = 0, high = n-1;
//     int idx = -1;

//     while(low <= high){
//         int mid = low + (high - low)/2;
//         if(arr[mid] == target){
//             idx = mid;
//             low = mid + 1;
//         }
//         else if(arr[mid] < target){
//             low = mid + 1;
//         }
//         else{
//             high = mid - 1;
//         }
//     }
//     return idx;
// }

int main(){
    vector<int> arr = {3,4,13,13,13,20,40};
    int target = 13;

    cout << last_occurrence(arr,target) << endl;

    return 0;
}