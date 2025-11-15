// Given an array, find length of longest subarray whose sum is 0

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;



// 1. Brute force approach  (TC : O(N*N)    SC : O(1)) 

// LOGIC : check all subarrays using 2 nested loops
// ALGORITHM : 
// calculate sum from i to j
// if sum == 0, update maxLen

// int longest_subarray(vector<int> &arr){
//     int n =arr.size();

//     int maxLength = 1;
//     for(int i=0; i<n; i++){
//         int sum = 0, length = 0;
//         for(int j=i; j<n; j++){
//             sum += arr[j];
//             if(sum == 0){
//                 length = j - i + 1;
//                 maxLength = max(maxLength, length);
//             }
//         }
//     }
//     return maxLength;
// }





// 2. Optimal approach  (TC : O(N)     SC : O(N))

// LOGIC : if 2 indices have same prefix sum, subarray between them has sum = 0
// ALGORITHM: 
// traverse array :
//      -> calculate sum
//      -> if(sum == 0) length = i + 1;
//      -> if (hashMap.find(sum) != hashMap.end()) length = i - hashMap[sum]
//      -> else hashMap[sum]  = i

int longest_subarray(vector<int> &arr){
    int n = arr.size();

    unordered_map<int,int> hashMap;

    int maxLength = 0, sum = 0, length = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum == 0){
            length = i+1;
        }
        else if(hashMap.find(sum) != hashMap.end()){
            length = i - hashMap[sum];
        }
        else{
            hashMap[sum] = i;
        }
        maxLength = max(maxLength, length);
    }

    return maxLength;
}

int main(){
    vector<int> arr = {6, -2, 2, -8, 1, 7, 4, -10};

    cout << longest_subarray(arr) << endl;

    return 0;
}