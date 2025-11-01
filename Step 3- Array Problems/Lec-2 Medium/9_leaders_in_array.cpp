// Given an array, print all the elements which are leaders
// leaders - elements greater than all the elements to right 

//  *** LAST element is ALWAYS leader ***

#include<iostream>
#include<vector>
using namespace std;


// 1. Brute force (2 loops)
// loop-1 : pick elements in array
// loop-2 : scans to find if greater number exits 
//           if exits then go to next element, otherwise store in ans

// TC : O(N*N)   SC : O(1) 

vector<int> leaders(vector<int> &arr){
    int n = arr.size();
    vector<int> ans;    // Used for output, not auxiliary space

    for(int i=0; i<n; i++){
        bool greater = true;
        for(int j=i; j<n; j++){
            if(arr[i] < arr[j]){
                greater = false;
            }
        }
        if(greater){
            ans.push_back(arr[i]);
        }
    }
    return ans;
}



// 2. Optimal approach 
// Traverse from right to left (righmost is leader)
// Keep track of max so far
// if arr[i] > max -> leader
// update max = arr[i] and store arr[i] in ans

// TC : O(N)    SC : O(1)

// vector<int> leaders(vector<int> &arr){
//     int n = arr.size(); 
//     vector<int> ans;   // used for output so not counted in SC

//     int max = arr[n-1];
//     ans.push_back(max);
//     for(int i=n-2; i>=0; i--){
//         if(arr[i] > max){
//             max = arr[i];
//             ans.push_back(max);
//         }
//     }
//     return ans;
// }

int main(){
    vector<int> arr = {10, 22, 12, 3, 0, 6};

    vector<int> ans = leaders(arr);

    for(int val : ans){
        cout << val << " "; 
    }
    cout << endl;

    return 0;
}