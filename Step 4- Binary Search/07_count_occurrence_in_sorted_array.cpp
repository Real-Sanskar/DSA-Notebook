// given a sorted array of size n and a target
// find the occurrence of target in array

#include<iostream>
#include<vector>
using namespace std;


// 1. Brute force approach (Linear Search)  (TC : O(N)   SC : O(1))

// check for target at each index, update count if found

// int count_occurrence(vector<int> &arr, int target){
//     int n = arr.size();

//     int count = 0;
    
//     for(int i=0; i<n; i++){
//         if(arr[i] == target){
//             count++;
//         }
//     }
//     return count;
// }



// 2. Optimal Solution (Binary Search)    (TC : O(logN)  SC : O(1))

// Find first occurrence of target
// Find last occurrence of target
// find total occurrence by formula : (lastIdx - firstIdx + 1)

int first_occurrence(vector<int> &arr, int target){
    int n = arr.size();

    int low = 0, high = n-1;
    int idx = -1;

    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[mid] == target){
            idx = mid;
            high = mid - 1;
        }
        else if(arr[mid] > target){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return idx;

}


int last_occurrence(vector<int> &arr, int target){
    int n = arr.size();

    int low = 0, high = n-1;
    int idx = -1;

    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[mid] == target){
            idx = mid;
            low = mid + 1;
        }
        else if(arr[mid] > target){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return idx;
}

int count_occurrence(vector<int> &arr, int target){
    int firstIdx = first_occurrence(arr,target);
    int lastIdx = last_occurrence(arr,target);
    
    return (lastIdx - firstIdx + 1);
}

int main(){
    vector<int> arr = {2,2,3,3,3,3,4};
    int target = 3;


    cout << count_occurrence(arr,target) << endl;

    return 0;
}