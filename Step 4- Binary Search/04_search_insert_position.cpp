// given an array and a target, 
// 1. return index if found
// 2. else return position where it could be inserted

#include<iostream>
#include<vector>
using namespace std;


// 1. Linear search (TC : O(N)    SC : O(1))

// int insert_position(vector<int> &arr, int target){
//     int n = arr.size();
//     int idx = n;

//     for(int i=0; i<n; i++){
//         if(arr[i] >= target){
//             return i;
//         }
//     }
//     return idx;
// }


// Binary Search (TC : O(log N)   SC : O(1))

// NOTE - Same as lower bound implementation
// 1. initialize low and high pointers
// 2. initialize idx variable with n
// 3. iterate while(low <= high)
// 4. if(arr[mid] >= target) -> ans = mid, high = mid + 1
// 5. else -> low = mid + 1

int insert_position(vector<int> &arr, int target){
    int n = arr.size();
    int low = 0, high = n-1;
    int ans = n;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] >= target){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,4,7};
    int target = 9;


    cout << insert_position(arr,target) << endl;

    return 0;
}