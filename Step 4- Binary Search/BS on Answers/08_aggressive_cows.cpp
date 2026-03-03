// given an array denoting position of stalls, and integer k denoting no. of cows
// assing stalls to k cows such that minimum distance between any 2 cows in maximum

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// The basic idea is to test every possible distance between 1 and the difference between the farthest and
//  nearest stalls. The largest distance for which canWePlace() returns true will be our answer.

bool canWePlace(vector<int> &arr, int dist, int cows){
    int n = arr.size();
    int cowCount = 1, lastStall = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] - lastStall >= dist){
            cowCount++;
            lastStall = arr[i];
        }
        if(cowCount == cows){
            return true;
        }
    }
    return false;
}

// int distance(vector<int> &arr, int k){
//     int n = arr.size();
//     sort(arr.begin(),arr.end());
//     int maxVal = arr[n-1] - arr[0];
//     int ans = 0;

//     for(int i=1; i<=maxVal; i++){
//         if(canWePlace(arr,i,k)){
//             ans = i;
//         }
//     }
//     return ans;
// }




int distance(vector<int> &arr, int k){
    int n = arr.size();
    int ans = -1;

    sort(arr.begin(),arr.end());
    int low = 1, high = arr[n-1] - arr[0];

    while(low <= high){
        int mid = low + (high-low)/2;

        if(canWePlace(arr,mid,k)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {0,3,4,7,10,9};
    int k = 4;

    cout << distance(arr,k) << endl;

    return 0;
}