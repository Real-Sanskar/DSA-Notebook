// Given an array of 0,1,2
// In-place sort the array without using in-built sort functions

#include<iostream>
#include<vector>
using namespace std;

// 1. Better approach (Keeping count of 0,1,2)
// TC : O(N) + O(N)    SC : O(1)

// void sort_array(vector<int> &arr){
//     int n = arr.size();
//     int count_0 = 0, count_1 = 0, count_2=0;

//     for(int i=0; i<n; i++){
//         if(arr[i] == 0){
//             count_0++;
//         }
//         else if(arr[i] == 1){
//             count_1++;
//         }
//         else{
//             count_2++;
//         }
//     }

//     for(int i=0; i<n; i++){
//         if(count_0 > 0){
//             arr[i] = 0;
//             count_0--;
//         }
//         else if(count_1 > 0){
//             arr[i] = 1;
//             count_1--;
//         }
//         else{
//             arr[i] = 2;
//             count_2--;
//         }
//     }
    
//     for(auto val : arr){
//         cout << val << " ";
//     }
// }



// 2. DNF(Dutch National Flag algorithm)
// Uses 3 pointers : low, mid and high
// 0 - low-1 : 0s
// low - mid-1 : 1s
// high+1 - n-1 : 2s

// mid - high : unsorted part of array

// TC : O(N)  SC: O(1)

void sort_array(vector<int> &arr){
    int n = arr.size();

    int low = 0, mid = 0, high = n-1;

    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }

    for(auto val : arr){
        cout << val << " ";
    }
    cout << endl;
}


int main(){
    vector<int> arr = {2,0,2,1,1,0};

    sort_array(arr);

    return 0;
}