// Roatate an array by k elements either left or right

#include<bits/stdc++.h>
using namespace std;

// 1. Brute force approach (using temp array)
// TC : O(N)  SC : O(N)

// (A). Left rotate
void rotate_left(vector<int> &arr, int k){
    int n = arr.size();
    
    k = k % n; // If k is greater than n

    if(n == 0){
        return;
    }
    if(k == 0) return;

    vector<int> temp(k);

    // store first k elements in temp
    for(int i=0; i<k; i++){
        temp[i] = arr[i];
    }

    // shifting n-k elements to right by k elements
    for(int i=k; i<n; i++){
        arr[i-k] = arr[i];
    }

    // inserting first k elements at last
    for(int i=n-k; i<n; i++){
        arr[i] = temp[i-n+k];
    }

    cout << "Array after rotating left by k elements: ";
    for(auto val:arr){
        cout << val << " ";
    }
    cout << endl;

}

// (B). right rotate
// void rotate_right(vector<int> &arr, int k){
//     int n = arr.size();

//     k = k % n ;   // If k is greater than n

//     if(n == 0) return;

//     if(k == 0) return;

//     vector<int> temp(k);

//     // storing last k elements in temp
//     for(int i=n-k; i<n; i++){
//         temp[i-(n-k)] = arr[i];
//     }

//     // shifiting n-k elements to right by k elements
//     for(int i = n-k-1; i>=0; i--){   // n-k-1 instead of k because it will be wrong when k is greater than n/2
//         arr[i+k] = arr[i];
//     }

//     // inserting last k elements at first
//     for(int i=0; i<k; i++){
//         arr[i] = temp[i];
//     }

//     cout << "Array after shifting k elements to right: ";
//     for(auto val: arr){
//         cout << val << " ";
//     }
//     cout << endl;
// }

int main(){
    vector<int> arr = {1,2,3,4,5};
    int k = 2;

    rotate_left(arr,k);
    // rotate_right(arr,k);

    return 0;
}