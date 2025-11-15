// Given an array and integer k, count number of subarrays whose XOR equals k

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;



// 1. Brute force approach (TC : O(N*N*N)    SC : O(1))

// LOGIC : explictly compute xor with 3 nested loops
// ALGORITHM : 
// i : starting index  ,   j: ending index
// k : from i to j, compute xor 
// if xor == k, increament count

// int count_subarray(vector<int> &arr, int k){
//     int n = arr.size();

//     int count = 0;
//     for(int i=0; i<n; i++){
//         for(int j=i; j<n; j++){
//             int xorr = 0;
//             for(int K=i; K<= j; K++){
//                 xorr = xorr ^ arr[K];
//             }
//             if(xorr == k){
//                 count++;
//             }
//         }
//     }
//     return count;
// }




// 2. Better approach (2 loops)  (TC : O(N*N)    SC : O(1))

// LOGIC : check all subarrays (i,j) and compute xor
// ALGORITHM :
// for each i, compute xor for indices j>=i
// if xor == k, increament count

// int count_subarray(vector<int> &arr, int k){
//     int n = arr.size();

//     int count = 0;
//     for(int i=0; i<n; i++){
//         int sum = 0;
//         for(int j=i; j<n; j++){
//             sum = sum ^ arr[j];
//             if(sum == k){
//                 count++;
//             }
//         }
//     }
//     return count;
// }





// 3. Optimal approach (prefix XOR + HashMap)   (TC : O(N)    SC : O(N))

// LOGIC : compute prefix xor and try to find it in hash map
// ALGORITHM :
// create a hashMap {XOR : freq}
// initialize map[0] = 1
// iterate over array : 
//      -> xor ^= arr[i]
//      -> if(xor == k) count++
//      -> check if (xor ^ k) exits in map
//      -> count += map[xor ^ k]
//      -> map[xor]++;

int count_subarray(vector<int> &arr, int k){
    int n = arr.size();

    unordered_map<int,int> hashMap;

    hashMap[0] = 1;

    int count = 0, xorr = 0;
    for(int i=0; i<n; i++){
        xorr ^= arr[i];
        if(xorr == k){
            count++;
        }
        if(hashMap.find(xorr ^ k) != hashMap.end()){
            count += hashMap[xorr ^ k];
        }
        hashMap[xorr]++;
    }
    return count;
}

int main(){
    vector<int> arr = {4,2,2,6,4};
    int k = 6;

    cout << count_subarray(arr,k) << endl;

    return 0;
}