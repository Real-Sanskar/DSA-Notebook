// given an array and an integer x, find :
// floor : largest element <= x
// ceil : smallest elment >= x

#include<iostream>
#include<vector>
using namespace std;



// Binary Search (TC : O(log N)    SC : O(1))

// 1. use 2 functions to calculate floor and ceil separately 
// for floor:
//      initialize low and high pointer, floor = -1
//      iterate while (low <= high)
//      if(arr[mid] <= x) -> potential floor -> search right
//      else -> search left

// for ceil :
//      initialize low and high pointer, ceil = -1
//      iterate while (low <= high)
//      if(arr[mid] >= x) -> potential ceil -> search left
//      else -> search right

int findFloor(vector<int> &arr, int x){
    int n = arr.size();
    int low = 0, high = n-1;
    int floor = -1;

    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] <= x){
            floor = arr[mid];
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return floor;
}

int findCeil(vector<int> &arr, int x){
    int n = arr.size();
    int low = 0, high = n-1;
    int ceil = -1;

    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] >= x){
            ceil = arr[mid];
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ceil;
}

pair<int,int> floor_ceiling(vector<int> &arr, int x){
    int floor = findFloor(arr,x);
    int ceil = findCeil(arr,x);

    return {floor,ceil};
}

int main(){
    vector<int> arr = {3,4,4,7,8,10};
    int x = 5;

    pair<int,int> ans = floor_ceiling(arr,x);

    cout << ans.first << " " << ans.second << endl;

    return 0;
}