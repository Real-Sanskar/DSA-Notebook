#include<bits/stdc++.h>
using namespace std;

// || RECURSION / BACKTRACKING (COMBINATION SUM II) ||

// =========================================================
// COMBINATION SUM II — UNIQUE COMBINATIONS, EACH ELEMENT
// USED AT MOST ONCE
// =========================================================
//
// Problem (LeetCode 40 style):
//   Given an array arr[] that MAY CONTAIN DUPLICATES and a
//   target, find ALL UNIQUE combinations summing to target.
//
//   Rules:
//     - Each element may be used AT MOST ONCE.
//     - Combinations are unordered.
//     - No duplicate combinations in the output.
//
// ---------------------------------------------------------
// KEY DIFFERENCES FROM COMBINATION SUM I
// ---------------------------------------------------------
//
//   1. Array may have duplicates  -> must SORT first.
//   2. Each element used once     -> recurse at j+1, not j.
//   3. Must avoid duplicate combos -> skip equal elements at
//      the SAME recursion level (j > i && arr[j]==arr[j-1]).
//
// ---------------------------------------------------------
// KEY IDEA
// ---------------------------------------------------------
//
// Classic "for-loop" backtracking template:
//   At each recursion level, we try every index j from i to n-1
//   as the NEXT element of the combination. We:
//     - skip duplicates at the same level
//     - break early if arr[j] > target (sorted, so no later
//       element can fit either)
//     - otherwise pick arr[j] and recurse from j+1
//
// "Same level" duplicate skip is the crucial trick:
//   After sorting, equal values are adjacent. If arr[j] ==
//   arr[j-1] AND j > i, then choosing arr[j] would produce
//   the same set of combinations as choosing arr[j-1] already
//   did at this level — so we skip it.
//
// ---------------------------------------------------------
// COMPLEXITY
// ---------------------------------------------------------
//
//   Sorting: O(N log N)
//   Recursion: exponential in worst case (bounded by number
//   of distinct combinations, heavily pruned by target).
//
//   TC: O(2^N) worst case
//   SC: O(N) recursion depth  +  output storage
// =========================================================

// ---------------------------------------------------------
// RECURSIVE HELPER (for-loop template)
// ---------------------------------------------------------
// i      : starting index for this level (elements before i
//          have already been considered in curr)
// n      : size of arr
// target : remaining sum still needed
// arr    : SORTED input array (may contain duplicates)
// ans    : stores all unique valid combinations
// curr   : current combination being built
void helper(int i, int n, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& curr){

    // ---------- base case: target reached ----------
    if(target == 0){
        ans.push_back(curr);
        return;
    }

    // ---------- try every candidate as the NEXT element ----------
    for(int j=i; j<n; j++){

        // DUPLICATE SKIP:
        // if arr[j] equals the previous element AND we're not
        // at the start of this level (j > i), picking arr[j]
        // would duplicate combinations already explored via
        // arr[j-1] at this same level -> skip it.
        if(j > i && arr[j] == arr[j-1]) continue;

        // PRUNE: since arr is sorted, if arr[j] exceeds the
        // remaining target, no later element can fit either.
        if(arr[j] > target) break;
        else{
            // pick arr[j]
            curr.push_back(arr[j]);
            // recurse from j+1 -> each element used AT MOST ONCE
            helper(j+1, n, (target - arr[j]), arr, ans, curr);
            // backtrack
            curr.pop_back();
        }
    }
}

// ---------------------------------------------------------
// WRAPPER: sort (required for duplicate-skip + pruning),
// then start recursion from index 0 with full target
// ---------------------------------------------------------
vector<vector<int>> combinationSum2(vector<int>& arr, int target){
    int n = arr.size();

    vector<vector<int>> ans;
    vector<int> curr;

    // SORT is mandatory: enables both
    //   (a) arr[j] == arr[j-1] duplicate check, and
    //   (b) early break when arr[j] > target
    sort(arr.begin(), arr.end());

    helper(0, n, target, arr, ans, curr);

    return ans;
}

int main(){
    vector<int> arr = {2, 1, 2, 7, 6, 1, 5};
    int target = 8;

    // get all unique combinations summing to target
    vector<vector<int>> ans = combinationSum2(arr, target);

    // print each combination on its own line
    for(auto& z: ans){
        for(auto& val: z){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}