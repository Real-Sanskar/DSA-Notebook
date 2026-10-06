#include<bits/stdc++.h>
using namespace std;


// =========================================================
// Generate all subsets using backtracking
//
// For every element, we have 2 choices:
// 1. Include the element
// 2. Exclude the element
//
// TC: O(2^N * N)
// SC: O(N) recursion stack
// =========================================================

void helper(vector<int>& arr, vector<vector<int>>& ans, vector<int>& curr, int i, int n){

    // base case: all elements are processed
    if(i >= n){

        // store the current subset
        // empty subset is added separately in powerSet()
        if(!curr.empty()){
            ans.push_back(curr);
        }

        return;
    }


    // 1. Include arr[i]
    curr.push_back(arr[i]);

    // move to next element
    helper(arr, ans, curr, i+1, n);

    // backtrack: remove arr[i]
    // so we can try excluding it
    curr.pop_back();


    // 2. Exclude arr[i]
    // simply move to next element
    helper(arr, ans, curr, i+1, n);
}


// =========================================================
// Function to generate the power set
// =========================================================

vector<vector<int>> powerSet(vector<int>& arr){

    // number of elements
    int n = arr.size();

    // stores all subsets
    vector<vector<int>> ans;

    // empty subset is also a valid subset
    ans.push_back({});

    // stores the current subset
    vector<int> curr;


    // start from index 0
    helper(arr, ans, curr, 0, n);

    return ans;
}


int main(){

    // input array
    vector<int> arr = {1,2,3};


    // generate all subsets
    vector<vector<int>> ans = powerSet(arr);


    // print all subsets
    for(auto& set: ans){

        for(int val: set){
            cout << val << " ";
        }

        cout << endl;
    }


    return 0;
}