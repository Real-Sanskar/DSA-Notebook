// Given a number N and an array of size N-1 containing elements from 1 to N
// Find the element missing from the array between 1 to N

#include<iostream>
#include<vector>
using namespace std;

// 1. Brute force approach 
// TC : O(N*N)  SC : O(1)

// int find_Num(vector<int> &arr, int num){
//     for(int i=1; i<=num; i++){
//         bool found = false;
//         for(int j=0; j<num-1; j++){
//             if(arr[j] == i){
//                 found = true;
//             }
//         }
//         if(!found){
//             return i;
//         }
//     }
// }


// 2. Better approach (Hashing)
// TC : O(N) + O(N) = O(2N)    SC : O(N)

// int find_Num(vector<int> &arr, int num){
//     int n = arr.size();

//     int temp[num+1] = {0};
//     for(int i=0; i<n; i++){
//         temp[arr[i]] += 1;
//     }

//     for(int i=1; i<= num; i++){
//         if(temp[i] == 0){
//             return i;
//         }
//     }
// }

// 3. Optimal approach
// TC : O(N)  SC : O(1)

// int find_Num(vector<int> &arr, int num){
//     int n = arr.size();

//     int s1 = num *(num+1)/2;
//     int s2 = 0;

//     for(int i=0; i<n; i++){
//         s2 += arr[i];
//     }
//     return s1-s2;
// }


int find_Num(vector<int> &arr, int num){
    int n = arr.size();
    
    int xor1 = 0, xor2 = 0;

    for(int i=0; i<n; i++){
        xor1 = xor1 ^ (i+1);
        
        xor2 = xor2 ^ arr[i];
    }
    xor1 = xor1 ^ num;

    return xor1 ^ xor2;
}



int main(){
    vector<int> arr = {1,2,4,5};
    int num = 5;

    cout << find_Num(arr, num) << endl;

    return 0;
}