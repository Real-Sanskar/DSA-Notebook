// Given a rotated sorted array, find number of rotations of array

#include<iostream>
#include<vector>
#include<climits>
using namespace std;


// Same as "Find minimum in rotated sorted array"
// Return index insted of value

int count_rotation(vector<int> &arr){
    int n = arr.size();
    int low = 0, high = n-1;
    
    
    int minIdx = 0, ans = INT_MAX;

    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[low] < arr[high]){
            if(arr[low] < ans){
                ans = arr[low];
                minIdx = low;
            }
            break;
        }

        if(arr[mid] < arr[minIdx]){
            minIdx = mid;
        }

        if(arr[low] <= arr[mid]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return minIdx;
}

int main(){
    vector<int> arr = {4,5,6,7,0,1,2,3};

    cout << count_rotation(arr) << endl;

    return 0;
}