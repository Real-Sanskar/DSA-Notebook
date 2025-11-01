// Given an array and a sum k, print length of longest subarray that sums k

// BOTH POSITIVES AND NEGATIVES IN THIS CASE

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


// 1. Brute force approach (3 looops)
// loop-1 : staring point of subarray
// loop-2 : ending point of subarray
// loop-3 : calculating sum

// TC : O(N*N*N)   SC : O (1)

// int longest_subarray(vector<int> &arr, int k){
//     int n = arr.size();

//     int max_len = 0;
//     for(int i=0; i<n; i++){
//         for(int j=i; j<n; j++){
//             int sum = 0;
//             for(int K=i; K<=j; K++){
//                 sum += arr[K];
//             }
//             if(sum == k){
//                 max_len = max(max_len, j-i+1);
//             }
//         }
//     }
//     return max_len;
// }



// 2. Optimized brute force approach (2 loops)
// loop-1 : starting index of subarray
// loop-2 : ending index of subarray and calculate sum

// TC : O(N*N)  SC : (1)

// int longest_subarray(vector<int> &arr, int k){
//     int n = arr.size();

//     int max_len = 0;
//     for(int i=0; i<n; i++){
//         int sum = 0;
//         for(int j=i; j<n; j++){
//             sum += arr[j];

//             if(sum == k){
//                 max_len = max(max_len, j-i+1);
//             }
//         }
//     }
//     return max_len;
// }



// 3. Optimal approach (HashMap)
// -> calculate prefix sum
// -> if sum not found in map , store in map with index
// -> if (sum - k) exits in hashmap , subarray found

// TC : O(N)   SC : O(N)

int longest_subarray(vector<int> &arr, int k){
    int n = arr.size();

    unordered_map<int, int> prefix_sum;
    int sum = 0, max_len = 0;

    for(int i=0; i<n; i++){
        sum += arr[i];

        if(sum == k){
            int len = i + 1;
            max_len = max(max_len, len);
        }

        int rem = sum - k;
        if(prefix_sum.find(rem) != prefix_sum.end()){
            int len = i - prefix_sum[rem];
            max_len = max(max_len, len);
        }

        if(prefix_sum.find(sum) == prefix_sum.end()){
            prefix_sum[sum] = i;
        }
    }
    return max_len;
}


int main(){
    vector<int> arr = {-1,1,1};
    int k = 1;

    cout << longest_subarray(arr,k) << endl;

    return 0;
}


