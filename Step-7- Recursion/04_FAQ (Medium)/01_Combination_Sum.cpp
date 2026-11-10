#include<bits/stdc++.h>
using namespace std;

// || RECURSION / BACKTRACKING (COMBINATION SUM) ||

// =========================================================
// COMBINATION SUM — ALL COMBINATIONS THAT SUM TO TARGET
// =========================================================
//
// Problem (LeetCode 39 style):
//   Given an array arr[] of distinct positive integers and a
//   target, find ALL UNIQUE combinations of arr[] elements
//   whose sum equals the target.
//
//   - Each element may be used UNLIMITED number of times.
//   - Combinations are unordered (order within a combination
//     does not matter), so {2,2,3} and {3,2,2} are the same.
//
// ---------------------------------------------------------
// KEY IDEA: RECURSION WITH PICK / NOT-PICK + REUSE
// ---------------------------------------------------------
//
// The trick: when we PICK arr[i], we recurse at the SAME
// index i (not i+1). This lets arr[i] be reused multiple
// times in the same combination.
//
// When we DON'T PICK arr[i], we move to i+1 (we've decided
// arr[i] won't appear any further in this path).
//
// This single decision ("recurse at i vs i+1") naturally
// generates combinations without duplicates AND without
// needing a "used" array.
//
// ---------------------------------------------------------
// BASE CASES
// ---------------------------------------------------------
//
//   1. remaining == 0  ->  valid combination found, store it
//   2. i >= n          ->  out of elements, stop
//   3. remaining < 0   ->  overshot the target, stop
//                          (safe because all arr[i] > 0)
//
// ---------------------------------------------------------
// PRUNING
// ---------------------------------------------------------
//
//   We only PICK arr[i] if remaining >= arr[i] — i.e., adding
//   it won't overshoot the target. This avoids wasting a
//   recursive call just to immediately hit remaining < 0.
//
// ---------------------------------------------------------
// WHY NO DUPLICATE COMBINATIONS?
// ---------------------------------------------------------
//
//   The "pick at i, or move to i+1" branching forces each
//   combination to be built in exactly one canonical order:
//   elements are considered in increasing index order. So
//   {2,2,3} can only be formed by picking index 0 three
//   times-ish pattern, never as {3,2,2} separately.
//
// ---------------------------------------------------------
// COMPLEXITY
// ---------------------------------------------------------
//
//   Worst case: exponential in target / min(arr).
//   (Loosely O(2^(T/min)) branches, but heavily pruned.)
//
//   TC: exponential (target-dependent)
//   SC: O(T/min) recursion depth  +  O(#solutions * avg_len)
//       for the output
// =========================================================

// ---------------------------------------------------------
// RECURSIVE HELPER
// ---------------------------------------------------------
// i         : current index in arr
// n         : size of arr
// arr       : input array (distinct positive integers)
// ans       : stores all valid combinations
// curr      : current combination being built
// remaining : how much sum is still needed to hit target
void helper(int i, int n, vector<int>& arr, vector<vector<int>>& ans, vector<int>& curr, int remaining){

    // ---------- base case 1: target reached ----------
    if(remaining == 0){
        // current combination is valid -> record it
        ans.push_back(curr);
        return;
    }

    // ---------- base case 2 & 3: out of bounds / overshot ----------
    // i >= n      : no more elements to use
    // remaining<0 : sum already exceeded target
    // (safe since all arr[i] > 0)
    if(i >= n || remaining < 0) return;

    // ---------- 1. PICK arr[i] (if it fits) ----------
    if(remaining >= arr[i]){
        curr.push_back(arr[i]);
        // NOTE: recurse at SAME index i -> allows REUSE of arr[i]
        helper(i, n, arr, ans, curr, (remaining - arr[i]));
        // backtrack: remove arr[i] before trying not-pick
        curr.pop_back();
    }

    // ---------- 2. DON'T PICK arr[i] ----------
    // move to next index -> arr[i] won't be used again
    // in this path (this prevents duplicates)
    helper(i+1, n, arr, ans, curr, remaining);
}

// ---------------------------------------------------------
// WRAPPER: sets up ans, curr, and starts recursion at
// index 0 with full target as remaining sum
// ---------------------------------------------------------
vector<vector<int>> combinationSum(vector<int>& arr, int target){
    int n = arr.size();

    vector<vector<int>> ans;   // all valid combinations
    vector<int> curr;          // combination being built

    helper(0, n, arr, ans, curr, target);

    return ans;
}

int main(){
    vector<int> arr = {2,3,5,4};
    int target = 7;

    // get all combinations summing to target
    vector<vector<int>> ans = combinationSum(arr, target);

    // print each combination on its own line
    for(auto& z: ans){
        for(auto& val: z){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}