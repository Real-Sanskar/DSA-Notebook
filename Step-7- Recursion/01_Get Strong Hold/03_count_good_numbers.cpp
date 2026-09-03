#include<iostream>
using namespace std;


// MOD is used to keep the answer within a manageable range
// The problem requires the answer modulo 10^9 + 7
const int MOD = 1e9 + 7;


// =========================================================
// 1. Recursive Approach - Direct Counting
// =========================================================
//
// Idea:
// At every position, the number of possible digits depends
// on whether the position is even or odd.
//
// Even index positions:
// {0, 2, 4, 6, 8} -> 5 choices
//
// Odd index positions:
// {2, 3, 5, 7} -> 4 choices
//
// Instead of explicitly trying every digit, simply multiply
// by the number of choices available at each position.
//
// TC: O(N)
// SC: O(N) due to recursion stack
// =========================================================

// long long helper(int n, int i){

//     // all positions have been processed
//     // one valid number has been formed
//     if(i == n) return 1;


//     // even index -> 5 possible digits
//     if(i % 2 == 0){

//         // choose any of the 5 valid even digits
//         return (5 * helper(n, i+1)) % MOD;
//     }

//     // odd index -> 4 possible digits
//     else{

//         // choose any of the 4 valid prime digits
//         return (4 * helper(n, i+1)) % MOD;
//     }
// }


// int goodNum(int n){

//     // start processing from index 0
//     return (int)helper(n, 0);
// }


// =========================================================
// 2. Recursive Approach - Try Every Digit
// =========================================================
//
// Idea:
// Explicitly try every possible digit at every position.
//
// Even index:
// {0, 2, 4, 6, 8} -> 5 choices
//
// Odd index:
// {2, 3, 5, 7} -> 4 choices
//
// This approach actually explores all possible combinations,
// so it is much more expensive than the previous approach.
//
// TC: O(5^(N/2) * 4^(N/2))
// SC: O(N) due to recursion stack
// =========================================================

// int goodNum(int n, int i){

//     // all positions have been processed
//     // one valid number has been formed
//     if(i == n) return 1;

//     int result = 0;


//     // even index -> 5 possible digits
//     if(i % 2 == 0){

//         // try every possible even digit
//         for(int digit: {0,2,4,6,8}){

//             // move to the next position
//             // digit itself does not matter for the count
//             result = (result + goodNum(n, i+1)) % MOD;
//         }
//     }


//     // odd index -> 4 possible prime digits
//     else{

//         // try every possible prime digit
//         for(int digit: {2,3,5,7}){

//             // move to the next position
//             result = (result + goodNum(n, i+1)) % MOD;
//         }
//     }


//     // return total valid numbers from this position
//     return result;
// }


// =========================================================
// 3. Optimal Approach - Binary Exponentiation
// =========================================================
//
// Observation:
//
// For every even index:
// There are 5 choices -> {0,2,4,6,8}
//
// For every odd index:
// There are 4 choices -> {2,3,5,7}
//
// Therefore:
//
// Number of even positions = (n + 1) / 2
// Number of odd positions  = n / 2
//
// Total answer:
// 5^(number of even positions) *
// 4^(number of odd positions)
//
// We calculate these powers using Binary Exponentiation.
//
// TC: O(log N)
// SC: O(1)
// =========================================================


// =========================================================
// Function to calculate:
// base^exp % MOD
//
// Binary Exponentiation:
//
// If exp is odd:
//     ans = ans * base
//
// Square the base:
//
//     base = base * base
//
// Divide exponent by 2:
//
//     exp = exp / 2
//
// This reduces the exponent by half at every iteration.
// =========================================================

long long power(long long base, long long exp){

    // stores the final result
    long long ans = 1;


    // continue until exponent becomes 0
    while(exp > 0){

        // if exponent is odd:
        // current base contributes to the answer
        if(exp % 2 == 1){
            ans = (ans * base) % MOD;
        }


        // square the base
        // because the exponent is going to be divided by 2
        base = (base * base) % MOD;


        // reduce exponent by half
        exp = exp / 2;
    }


    // return base^exp % MOD
    return ans;
}


// =========================================================
// Function to calculate the number of good numbers
// =========================================================

int goodNum(long long n){

    // number of even index positions
    //
    // Example:
    // n = 5
    // indices = 0,1,2,3,4
    // even indices = 0,2,4 -> 3
    //
    // (5 + 1) / 2 = 3
    long long evenPosition = (n + 1)/2;


    // number of odd index positions
    //
    // Example:
    // n = 5
    // odd indices = 1,3 -> 2
    //
    // 5 / 2 = 2
    long long oddPosition = n / 2;


    // each even position has 5 choices
    //
    // total ways contributed by even positions:
    // 5^(number of even positions)
    long long evenWays = power(5, evenPosition);


    // each odd position has 4 choices
    //
    // total ways contributed by odd positions:
    // 4^(number of odd positions)
    long long oddWays = power(4, oddPosition);


    // multiply the choices from both types of positions
    //
    // Example:
    // n = 2
    //
    // index 0 -> 5 choices
    // index 1 -> 4 choices
    //
    // answer = 5 * 4 = 20
    return (evenWays * oddWays) % MOD;
}


int main(){

    // length of the good number
    int n = 2;


    // calculate and print number of good numbers
    //
    // For n = 2:
    // even positions = 1 -> 5 choices
    // odd positions  = 1 -> 4 choices
    //
    // answer = 5 * 4 = 20
    cout << goodNum(n) << endl;


    // previous recursive approach
    // cout << goodNum(n, 0) << endl;


    return 0;
}