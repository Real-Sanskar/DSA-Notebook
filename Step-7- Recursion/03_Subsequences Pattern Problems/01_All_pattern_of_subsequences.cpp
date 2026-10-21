#include<bits/stdc++.h>
using namespace std;


// || ALL SUBSEQUENCE PATTERN ||


// =========================================================
// 1. PRINT ALL SUBSEQUENCES WITH SUM K
// =========================================================
//
// At every index, we have 2 choices:
// 1. Pick the element
// 2. Don't pick the element
//
// At the base case, print the subsequence if its sum == k.
//
// TC: O(2^N * N)
// SC: O(N) recursion stack + subsequence
// =========================================================

// void printS(vector<int>& arr, vector<int>& ds, int sum, int i, int n, int s){

//     // base case: all elements have been processed
//     if(i == n){

//         // print only subsequences whose sum equals k
//         if(s == sum){
//             for(auto& val: ds) cout << val << " ";
//             cout << endl;
//         }

//         return;
//     }


//     // 1. Pick arr[i]
//     ds.push_back(arr[i]);
//     s += arr[i];

//     // move to next index with the current element included
//     printS(arr, ds, sum, i+1, n, s);


//     // backtrack: remove arr[i] and restore the sum
//     ds.pop_back();
//     s -= arr[i];


//     // 2. Don't pick arr[i]
//     printS(arr, ds, sum, i+1, n, s);
// }


// int main(){
//     vector<int> arr = {1, 2, 1};
//     int n = 3;
//     vector<int> ds;
//     int sum = 2;

//     printS(arr, ds, sum, 0, n, 0);

//     return 0;
// }




// =========================================================
// 2. PRINT ONLY ONE SUBSEQUENCE WITH SUM K
// =========================================================
//
// Same pick / not-pick logic, but return true as soon as
// one valid subsequence is found.
//
// Returning true stops further recursive exploration.
//
// TC: O(2^N * N) worst case
// SC: O(N) recursion stack + subsequence
// =========================================================

// bool printS(vector<int>& arr, vector<int>& ds, int sum, int i, int n, int s){

//     // base case: all elements have been processed
//     if(i == n){

//         // condition satisfied
//         if(sum == s){
//             for(auto& val: ds) cout << val << " ";
//             cout << endl;

//             return true;  // signal that an answer was found
//         }

//         // no valid subsequence on this path
//         return false;
//     }


//     // 1. Pick arr[i]
//     ds.push_back(arr[i]);
//     s += arr[i];

//     // if the pick branch finds an answer,
//     // stop exploring and pass true to previous calls
//     if(printS(arr, ds, sum, i+1, n, s) == true){
//         return true;
//     }


//     // backtrack only if the pick branch found no answer
//     ds.pop_back();
//     s -= arr[i];


//     // 2. Don't pick arr[i]
//     if(printS(arr, ds, sum, i+1, n, s) == true){
//         return true;
//     }

//     // neither branch found a valid subsequence
//     return false;
// }


// int main(){
//     vector<int> arr = {1, 2, 1};
//     int n = 3;
//     int sum = 2;
//     vector<int> ds;

//     printS(arr, ds, sum, 0, n, 0);

//     return 0;
// }




// =========================================================
// 3. COUNT ALL SUBSEQUENCES WITH SUM K
// =========================================================
//
// Instead of storing or printing subsequences, return the
// number of valid subsequences.
//
// Pick branch    -> count valid subsequences including arr[i]
// Not-pick branch -> count valid subsequences excluding arr[i]
//
// Add both counts to get the total.
//
// TC: O(2^N) worst case
// SC: O(N) recursion stack
// =========================================================

int countS(vector<int>& arr, int sum, int i, int n, int s){

    // pruning: if sum already exceeds the target,
    // this path cannot produce the target sum
    //
    // IMPORTANT: this is valid only when all array
    // elements are non-negative.
    if(s > sum){
        return 0;
    }


    // base case: all elements have been processed
    if(i == n){

        // this subsequence satisfies the target sum
        if(sum == s){
            return 1;
        }

        // this subsequence does not satisfy the target
        return 0;
    }


    // 1. Pick arr[i]
    s += arr[i];

    // count valid subsequences that include arr[i]
    int leftCount = countS(arr, sum, i+1, n, s);


    // backtrack: remove arr[i] from the sum
    // before exploring the not-pick branch
    s -= arr[i];


    // 2. Don't pick arr[i]
    // count valid subsequences that exclude arr[i]
    int rightCount = countS(arr, sum, i+1, n, s);


    // total valid subsequences from both branches
    return leftCount + rightCount;
}


int main(){

    // input array
    vector<int> arr = {1,2,1};

    int n = 3;

    // target sum
    int sum = 2;


    // count subsequences whose sum equals the target
    int count = countS(arr, sum, 0, n, 0);


    // print the total count
    cout << count << endl;


    return 0;
}