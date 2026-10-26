#include<bits/stdc++.h>
using namespace std;

// || SUBSEQUENCE SUM == K (EXISTENCE CHECK) ||

// =========================================================
// CHECK IF ANY SUBSEQUENCE WITH SUM K EXISTS
// =========================================================
//
// Problem: Given an array arr[] and an integer k, determine
// whether there exists at least one subsequence whose sum
// is exactly equal to k.
//
// Approach: Pick / Not-Pick recursion
// At every index i, we have 2 choices:
//   1. Pick arr[i]     -> add it to running sum s
//   2. Don't pick arr[i] -> skip it
//
// We use "return true as soon as one valid subsequence is
// found" trick. Returning true bubbles up the call stack and
// short-circuits further exploration — so we don't waste time
// checking remaining branches once an answer is found.
//
// Base case: when i == n (all elements processed),
//            return true if s == k, else false.
//
// TC: O(2^N) worst case (when no valid subsequence exists)
// SC: O(N) recursion stack
// =========================================================

bool helper(vector<int>& arr, int k, int i, int n, int s){

    // base case: all elements processed
    if(i == n){

        // check if the accumulated sum equals target k
        if(s == k){
            return true;
        }
        // this path did not produce the target sum
        return false;
    }

    // ---------- 1. PICK arr[i] ----------
    s += arr[i];

    // if the pick branch finds a valid subsequence,
    // propagate true upward immediately (short-circuit)
    if(helper(arr, k, i+1, n, s) == true){
        return true;
    }

    // backtrack: undo the pick before trying the not-pick branch
    s -= arr[i];

    // ---------- 2. DON'T PICK arr[i] ----------
    // if the not-pick branch finds a valid subsequence,
    // propagate true upward
    if(helper(arr, k, i+1, n, s) == true){
        return true;
    }

    // neither branch found a valid subsequence
    return false;
}

// wrapper function: extracts size and starts recursion from
// index 0 with running sum 0
bool checkSubsequenceSum(vector<int>& arr, int k){
    int n = arr.size();

    return helper(arr, k, 0, n, 0);
}

int main(){
    // input array
    vector<int> arr = {1,2,3,4,5};
    // target sum
    int k = 8;

    // check existence of any subsequence with sum == k
    if(checkSubsequenceSum(arr, k)){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }

    return 0;
}