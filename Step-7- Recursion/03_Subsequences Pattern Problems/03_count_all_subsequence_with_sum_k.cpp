#include<bits/stdc++.h>
using namespace std;

// || ALL SUBSEQUENCE PATTERN (COUNT VARIANT) ||

// =========================================================
// COUNT ALL SUBSEQUENCES WITH SUM EQUAL TO K
// =========================================================
//
// Problem:
//   Given an array arr[] and a target k, count how many
//   subsequences of arr[] have sum exactly equal to k.
//
//   A subsequence is any subset of indices in their original
//   order (here order doesn't matter for the sum, so it's
//   effectively "pick / not pick each element").
//
// ---------------------------------------------------------
// KEY IDEA: RECURSION WITH PICK / NOT-PICK
// ---------------------------------------------------------
//
// At every index i, we branch into two choices:
//   1. PICK arr[i]      -> add it to running sum s
//   2. NOT PICK arr[i]  -> skip it
//
// Base case (i == n):
//   - return 1 if s == k  (this is one valid subsequence)
//   - return 0 otherwise
//
// The total count is the SUM of counts from both branches.
//
// Unlike the "print" version, we don't store the subsequence.
// Unlike the "exists" version, we don't short-circuit on the
// first hit — we must explore ALL paths to count them.
//
// ---------------------------------------------------------
// COMPLEXITY
// ---------------------------------------------------------
//
//   Every element gives 2 branches -> 2^N leaves.
//
//   TC: O(2^N)
//   SC: O(N) recursion stack
// =========================================================

// ---------------------------------------------------------
// RECURSIVE COUNTER
// ---------------------------------------------------------
// i   : current index
// n   : size of array
// arr : input array
// k   : target sum
// s   : running sum of chosen elements so far
//
// Returns: number of valid subsequences from index i onward
//          whose contribution makes the total reach k.
int countS(int i, int n, vector<int>& arr, int k, int s){

    // base case: all elements processed
    if(i == n){
        // this complete choice-set forms a valid subsequence
        if(s == k){
            return 1;
        }
        // this choice-set does not sum to k
        return 0;
    }

    // ---------- 1. PICK arr[i] ----------
    s += arr[i];
    // count valid subsequences that INCLUDE arr[i]
    int leftCount = countS(i+1, n, arr, k, s);

    // backtrack: undo pick before exploring not-pick branch
    s -= arr[i];

    // ---------- 2. DON'T PICK arr[i] ----------
    // count valid subsequences that EXCLUDE arr[i]
    int rightCount = countS(i+1, n, arr, k, s);

    // total = contributions from both branches
    return leftCount + rightCount;
}

// ---------------------------------------------------------
// WRAPPER: start recursion from index 0 with running sum 0
// ---------------------------------------------------------
int countSubsequenceWithTargetSum(vector<int>& arr, int k){
    int n = arr.size();

    return countS(0, n, arr, k, 0);
}

int main(){
    vector<int> arr = {4,9,2,5,1};
    int k = 10;

    // count subsequences whose sum equals k
    cout << countSubsequenceWithTargetSum(arr, k);

    return 0;
}