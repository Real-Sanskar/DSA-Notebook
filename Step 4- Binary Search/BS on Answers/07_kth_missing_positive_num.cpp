// find kth missing possitive integer from strictly increasing array

#include<bits/stdc++.h>
using namespace std;



// Linear Search (TC : O(N))
// If vec[i] <= k: we will simply increase the value of k by 1.
// Otherwise, we will break out of the loop.


// int missingNum(vector<int> &arr, int k){
//     for(int val: arr){
//         if(val <= k){
//             k++;
//         }
//         else{
//              break;
//         }
//     }
//     return k;
// }






// Binary Search (TC : O(logN))

// Logic: Binary search to find position where Kth missing occurs
// Key Formula:

// Missing numbers before index i: arr[i] - (i+1)

// Algorithm:

// Binary search to find largest index where missing < K
// Answer: K + low


int missingNum(vector<int> &arr, int k){
    int n = arr.size();
    int low = 0, high = n-1;

    while(low <= high){
        int mid = low + (high - low)/2;
        int missing = arr[mid] - (mid + 1);

        if(missing < k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low + k;  // key formula 
}

int main(){
    vector<int> arr = {4,7,9,10};
    int k = 5;

    cout << missingNum(arr,k) << endl;

    return 0;
}