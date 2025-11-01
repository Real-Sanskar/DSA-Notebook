// Given an array of size n 
// return array with alternating positive - negative values starting with 0
// ** without altering relative order of +ve and -ve elements

// *** EQUAL NUMBER OF +VE AND -VE ***

#include<iostream>
#include<vector>
using namespace std;

// 1. Brute force approach (2 pass)
// create pos[] and neg[] arrays
// Store positive and negative seperately
// Merge : merge both alternatively

// TC : O(2*N)     SC: O(N)

vector<int> rearrange(vector<int> arr){
    int n = arr.size();
    vector<int> positive,negative;

    for(int i=0; i<n; i++){
        if(arr[i] > 0){
            positive.push_back(arr[i]);
        }
        else{
            negative.push_back(arr[i]);
        }
    }

    vector<int> ans;
    for(int i=0; i< positive.size(); i++){
        ans.push_back(positive[i]);
        ans.push_back(negative[i]);
    }

    return ans;
}



// 2. Optimal approach (Single pass)
// LOGIC : place elements directly in correct positions using 2 pointers
// ALGORITHM :
// posIdx = 0 (even), negIdx = 1 (odd)
// if positive : ans[posIdx] , posIdx += 2
// if negative : ans[negIdx] , negIdx += 2

// TC : O(N)    SC : O(N)

// vector<int> rearrange(vector<int> arr){
//     int n = arr.size();
//     vector<int> ans(n,0);

//     int posIndex = 0, negIndex = 1;
//     for(int i=0; i<n; i++){
//         if(arr[i] > 0){
//             ans[posIndex] = arr[i];
//             posIndex += 2;
//         }
//         else{
//             ans[negIndex] = arr[i];
//             negIndex += 2;
//         }
//     }
//     return ans;
// }


int main(){
    vector<int> arr = {1,2,-4,-5};

   vector<int> ans = rearrange(arr);

    for(auto val : ans){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}