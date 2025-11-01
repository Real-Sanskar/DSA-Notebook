// Given an array and a sum k, print length of longest subarray that sums k

// ONLY POSITIVE IN THIS CASE

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

// 1. Brute force approach -> Using 3 loops
// loop 1 = starting index of subarray
// loop 2 = ending index of subarray
// loop 3 = calculating sum

// TC : O(N*N*N)   SC : O(1)

// int subarray_sum(vector<int> &arr, int K){
//     int n = arr.size();

//     int len = 0;
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             int sum = 0;
//             for(int k=i; k<=j; k++){
//                 sum += arr[k];
//             }

//             if(sum == K){
//                 len = max(len, j-i+1);
//             }
//         }
//     }
//     return len;
// }



// 2. Optimized brute force approach -> Using 2 loops
// loop 1 = starting index of subarray
// loop 2 = ending index of subarray and calculate sum
// if sum = k store max of previous max_subarray and current subarray

// TC : O(N*N)  SC : O(1)

// int subarray_sum(vector<int> &arr, int k){
//     int n = arr.size();
//     int max_length = 0;
//     for(int i=0; i<n; i++){
//         int sum = 0;
//         for(int j = i; j<n; j++){
//             sum += arr[j];
            
//             if(sum == k){
//                 max_length = max(j-i+1, max_length);
//                 break;
//             }
//         }
//     }
//     return max_length;
// }



// 3. Better approach (HashMap) --> prefixsum, if found x - k in map then subarray exists

// TC : O(N)   SC : O(N)

// int subarray_sum(vector<int> &arr, int k){
//     int n = arr.size();

//     unordered_map<long long, int> prefixSum;

//     int sum = 0;
//     int max_len = 0;
//     for(int i=0; i<n; i++){
//         sum += arr[i];

//         if(sum == k){
//             int len = i+1;
//             max_len = max(max_len,len);
//         }

//         int rem = sum - k;
//         if(prefixSum.find(rem) != prefixSum.end()){
//             int len = i - prefixSum[rem];
//             max_len = max(max_len,len);
//         }

//         if(prefixSum.find(sum) == prefixSum.end()){
//             prefixSum[sum] = i;
//         }
//     }
//     return max_len;  
// }



// 4. Sliding window --> Move right ptr -> sum > k  -> move left pointer

// TC : O(2*N)   SC : O(1)

int subarray_sum(vector<int> &arr, int k){
    int n = arr.size();
    int left = 0 , right = 0;
    int sum = arr[0];
    int max_len = 0;

    while(right < n){
        while(left <= right && sum > k){
            sum -= arr[left];
            left++;
        }

        if(sum == k){
            max_len = max(max_len, right-left +1);
        }
        
        right++;
        if(right < n){
            sum += arr[right]; 
        }
    }
    return max_len;
}

int main(){
    vector<int> arr = {2,3,5,1,9};
    int k = 10;

    cout << subarray_sum(arr,k) << endl;

    return 0;
}