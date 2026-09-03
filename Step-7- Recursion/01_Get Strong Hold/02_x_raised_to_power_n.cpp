#include<iostream>
using namespace std;


// =========================================================
// 1. Brute Force Approach
// =========================================================
//
// Idea:
// Multiply x by itself n times.
//
// Example:
// x = 2, n = 5
// 2 * 2 * 2 * 2 * 2 = 32
//
// TC: O(N)
// SC: O(1)
// =========================================================

// double myPow(double x, int n){

//     // if n = 0, answer is 1
//     // x^0 = 1
//     if(n == 0 || x == 1.0) return 1;

//     double ans = 1;

//     // use long long because n can be INT_MIN
//     // INT_MIN cannot be safely negated as an int
//     long long temp = n;

//     // handle negative power
//     //
//     // x^(-n) = 1 / x^n
//     //
//     // example:
//     // 2^(-3) = (1/2)^3
//     if(n < 0){
//         x = 1/x;
//         temp = -1 * 1LL * n;
//     }

//     // multiply x, n times
//     for(long long i = 0; i < temp; i++){
//         ans *= x;
//     }

//     return ans;
// }


// =========================================================
// 2. Optimal Approach - Binary Exponentiation
// =========================================================
//
// Idea:
// Instead of multiplying x n times, reduce the power by half
// at every recursive call.
//
// If n is even:
// x^n = x^(n/2) * x^(n/2)
//
// If n is odd:
// x^n = x^(n/2) * x^(n/2) * x
//
// Example:
// 2^10
// → 2^5
// → 2^2
// → 2^1
// → 2^0
//
// TC: O(log N)
// SC: O(log N) due to recursion stack
// =========================================================

double helper(double x, long long n){

    // base case:
    // any number raised to power 0 is 1
    if(n == 0) return 1.0;


    // if x = 1:
    // 1^n = 1
    if(x == 1) return x;


    // calculate x^(n/2) recursively
    // power is reduced by half at every step
    double half = helper(x, n/2);


    // if n is even:
    // x^n = x^(n/2) * x^(n/2)
    //
    // example:
    // 2^10 = 2^5 * 2^5
    if(n % 2 == 0){
        return half * half;
    }


    // if n is odd:
    // x^n = x^(n/2) * x^(n/2) * x
    //
    // example:
    // 2^5 = 2^2 * 2^2 * 2
    else{
        return half * half * x;
    }
}


double myPow(double x, int n){

    // use long long because n can be INT_MIN
    // this allows us to safely calculate -num
    long long num = n;


    // handle negative power
    //
    // x^(-n) = (1/x)^n
    //
    // example:
    // 2^(-3) = (1/2)^3
    if(num < 0){
        return helper(1/x, -num);
    }


    // for positive power:
    // directly calculate x^n
    else{
        return helper(x, num);
    }
}


int main(){

    // input value
    double x = 2.0000;

    // power
    int n = 10;


    // calculate x^n
    //
    // 2^10 = 1024
    double ans = myPow(x, n);


    // print result
    cout << ans << endl;


    return 0;
}