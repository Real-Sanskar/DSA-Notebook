// Given an integer array (having both +ve and -ve numbers), find contiguous subarray that has largest product

#include<iostream>
#include<vector>
#include<climits>
using namespace std;



// 1. Brute force (TC : O(N*N)   SC : O(1))

// compute product of all subarrays

// int max_product(vector<int> &arr){
//     int n = arr.size();

//     int maxProduct = INT_MIN;
//     for(int i=0; i<n; i++){
//         int currProduct = 1;
//         for(int j=i; j<n; j++){
//             currProduct *= arr[j];
//             maxProduct = max(maxProduct,currProduct);
//         }
//     }
//     return maxProduct;
// }




// 2. Optmial approach (TC : O(N)   SC : O(1))

// Traverse from left -> right, keep running product, reset at zero
// Traverse from right -> left, same logic
// ans = max product seen in either scan
// Handles odd negatives implicitly skipping first/last negative

int max_product(vector<int> &arr){
    int n = arr.size();

    int ans = INT_MIN;
    int prefix = 1, suffix = 1;
    for(int i=0;i<n; i++){
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;

        prefix *= arr[i];
        suffix *= arr[n-1-i];

        ans = max(ans,max(prefix,suffix));
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,-1,-4,-5};

    cout << max_product(arr) << endl;

    return 0;
}