#include<iostream>
using namespace std;


// ---------------------------------------------------------
// 1. Brute Force Approach:
// Multiply x, n times.
//
// TC: O(N)
// SC: O(1)
// ---------------------------------------------------------

// double myPow(double x, int n){
//     // if n = 0, answer is 1
//     // x^0 = 1
//     if(n == 0 || x == 1.0) return 1;
//
//     double ans = 1;
//
//     // use long long because n can be INT_MIN
//     long long temp = n;
//
//     // for negative power:
//     // x^(-n) = 1 / x^n
//     if(n < 0){
//         x = 1/x;
//         temp = -1 * 1LL * n;
//     }
//
//     // multiply x, n times
//     for(int i=0; i<n; i++){
//         ans *= x;
//     }
//     
//     return ans;
// }



// ---------------------------------------------------------
// 2. Optimal Approach:
// Binary Exponentiation / Fast Power
//
// Instead of multiplying x n times, reduce n by half
// whenever n is even.
//
// Example:
// x^10 = (x^2)^5
// x^5  = x * x^4
//
// TC: O(log N)
// SC: O(log N) due to recursion
// ---------------------------------------------------------

// helper function to calculate x^n recursively
double helper(double x, int n){

    // base case:
    // anything raised to power 0 is 1
    if(n == 0) return 1.0;


    // x^n will always be 1 when x = 1
    // this also avoids unnecessary recursive calls
    if(x == 1) return x;


    double ans = 1;


    // if n is even:
    //
    // x^n = (x^2)^(n/2)
    //
    // Example:
    // x^10 = (x^2)^5
    //
    // So instead of calculating 10 multiplications,
    // reduce the power from 10 to 5.
    if(n % 2 == 0){
        return helper(x*x, n/2);
    }


    // if n is odd:
    //
    // x^n = x * x^(n-1)
    //
    // n-1 becomes even, so the next call can use
    // the even case to divide the power by 2.
    //
    // Example:
    // x^5 = x * x^4
    else{
        return x * helper(x, n-1);
    }
}


// function to calculate x raised to power n
double myPow(double x, int n){

    // store n separately
    int num = n;


    // handle negative power
    //
    // x^(-n) = 1 / x^n
    //
    // Example:
    // 2^(-3) = 1 / 2^3
    if(num < 0){
        return (1.0 / helper(x, -1 * num));
    }


    // for positive power, directly calculate x^n
    return helper(x, num);
}


int main(){

    double x = 2.0000;
    int n = 10;


    // calculate x^n
    //
    // 2^10 = 1024
    double ans = myPow(x, n);


    // print result
    cout << ans << endl;


    return 0;
}