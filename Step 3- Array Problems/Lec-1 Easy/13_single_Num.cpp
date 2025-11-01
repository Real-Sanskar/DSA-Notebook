// Given a non-empty array, every element repeats once except one
// Return that element

// Problem : Single Num 
// Pattern : XOR trick

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

// 1. Brute force approach
// TC : O(N*N)   SC : O(1)

// int single_num(vector<int> &arr){
//     int n = arr.size();

//     for(int i=0; i<n; i++){
//         bool found = false;
//         for(int j=i+1; j<n; j++){
//             if(arr[i] == arr[j]){
//                 found = true;
//             }
//         }
//         if(!found){
//             return arr[i];
//         }
//     }
// }




// 2. Better approach (Array hashing)
// ***NOT APPLICABLE FOR NEGATIVE OR VERY LARGE ARRAY***

// TC : O(N)   SC : O(N)

// int single_num(vector<int> &arr){
//     int n = arr.size();

//     int max_ele = arr[0];
//     for(int i=0; i<n; i++){
//         max_ele = max(max_ele,arr[i]);
//     }
    
//     vector<int> hash(max_ele+1, 0);
//     for(int i=0; i<n; i++){
//         hash[arr[i]]++;
//     }

//     for(int i=0; i<n; i++){
//         if(hash[arr[i]] == 1){
//             return arr[i];
//         }
//     }
// }




// 3. Hashing (Mapping)
// TC : O(N)   SC : O(N)

// int single_num(vector<int> &arr){
//     int n = arr.size();

//     unordered_map<int,int> hash;

//     for(int i=0; i<n; i++){
//         hash[arr[i]]++;
//     }

//     for(auto val : hash){
//         if(val.second == 1){
//             return val.first;
//         }
//     }
// }




// 4. Using bitwise XOR
// TC : O(N)   SC : O(1)

int single_num(vector<int> &arr){
    int n = arr.size();

    int result = 0;
    for(int i=0; i<n; i++){
        result = result ^ arr[i];
    }

    return result;
}


int main(){
    vector<int> arr = {4,1,2,1,2};

    cout << single_num(arr) << endl;

    return 0;
}