// Given an array of borads and k painters, asssign boards to k painters such that time taken in minimized
// Unit board is painted in unit time

#include<bits/stdc++.h>
using namespace std;


int paintersNeeded(vector<int> &arr, int time){
    int painter = 1, boardLength = 0;

    for(int i=0; i<arr.size(); i++){
        if(boardLength + arr[i] <= time){
            boardLength += arr[i];
        }
        else{
            painter++;
            boardLength = arr[i];
        }
    }
    return painter;
}


// Linear Search (TC : O(sum - max) * O(N))

// Try all possible maxTime from max(arr) to sum(arr)
// for each maxTime, count painters needed
// if painters == k -> return maxTime (first valid is minimum)


// int timeNeeded(vector<int> &arr, int k){
//     int minVal = *max_element(arr.begin(),arr.end());
//     int maxVal = accumulate(arr.begin(),arr.end(),0);

//     for(int i=minVal; i<=maxVal; i++){
//         if(paintersNeeded(arr,i) == k){
//             return i;
//         }
//     }
//     return -1;
// }






// Binary Search (TC : O(log(sum - max)) * O(N))

// for each mid in answer space:
// check painters needed for this maxTime
// if valid -> ans = mid -> check for smaller time
// else -> check for larger time

int timeNeeded(vector<int> &arr, int k){
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    int ans = -1;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(paintersNeeded(arr,mid) <= k){
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
    vector<int> arr = {10,20,30,40};
    int k = 2;

    cout << timeNeeded(arr,k) << endl;

    return 0;
}