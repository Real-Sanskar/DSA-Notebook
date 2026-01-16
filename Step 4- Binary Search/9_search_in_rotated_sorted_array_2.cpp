// Given a rotated sorted array (not necessarily distinct) and a target
// If target found return true, else return false


#include<iostream>
#include<vector>
using namespace std;


// Key Problem with Duplicates:

// When arr[low] == arr[mid] == arr[high], we cannot determine which half is sorted
// Example: [1,0,1,1,1], mid=2, arr[0]=1, arr[2]=1, arr[4]=1
// Both halves could be sorted or unsorted!

// Solution: When arr[low] == arr[mid] == arr[high]:

// Shrink search space: low++, high--
// Skip duplicates from both ends

bool rotated_sorted(vector<int> &arr, int target){
    int n = arr.size();
    int low = 0, high = n-1;

    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[mid] == target){
            return true;
        }

        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            low++, high--;
        }

        if(arr[low] <= arr[mid]){
            if(arr[low] <= target && target < arr[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if(arr[mid] < target && target <= arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return false;
}

int main(){
    vector<int> arr = {1,0,1,1,1};
    int target = 0;

    if(rotated_sorted(arr,target)){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }

    return 0;
}