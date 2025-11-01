// Given an array of size n, return element that occurs more than n/2 times

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


// 1. Brute force approach (2 loops)
// loop-1 : picks each element
// loop-2 : it tries to find same element in array

// TC : O(N*N)   SC : O(1)

// int majority_element(vector<int> &arr){
//     int n = arr.size();

//     for(int i=0; i<n; i++){
//         int freq = 0;
//         for(int j=0; j<n; j++){
//             if(arr[i] == arr[j]){
//                 freq++;
//             }
//         }
//         if(freq > n/2){
//             return arr[i];
//         }
//     }
// }



// 2. Better approach (Using map)

// TC : O(N)   SC : O(N)

// int majority_element(vector<int> &arr){
//     int n = arr.size();

//     unordered_map<int,int> count;

//     for(int i=0; i<n; i++){
//         count[arr[i]]++;
//     }

//     for(auto val : count){
//         if(val.second > n/2){
//             return val.first;
//         }
//     }
// }



// 3. Optimal (Moore's Voting algorithm)

// TC : O(N)   SC : O(1)

int majority_element(vector<int> &arr){
    int n = arr.size();

    int ans, freq = 0;
    for(int i=0; i<n; i++){
        if(freq == 0){
            ans = arr[i];
            freq = 1;
        }
        if(arr[i] == ans){
            freq++;
        }
        else{
            freq--;
        }
    }
    return ans;
}


int main(){
    vector<int> arr = {2,2,1,1,1,2,2};

    cout << majority_element(arr) << endl;

    return 0;
}