// Given an integer N, find and return its sqaure root
// if 'N' is not a perfect square, return floor value of sqrt(n)

#include<iostream>
using namespace std;


// Linear Search (TC : O(N))
// check from 1 to n, find largest i such that i*i <= n

// int sqr_root(int n){
//     int ans = 0;

//     for(int i=1; i<=n; i++){
//         if(i*i <= n){
//             ans = i;
//         }
//         else{
//             break;
//         }
//     }
//     return ans;
// }



// Binary Search (TC : O(logN))
// Logic: Binary search on answer space (1 to n)

// - if (mid*mid <= n) -> ans = mid -> move right (maximum mid)
// - if(mid*mid > n) -> move left


int sqr_root(int n){
    int ans = 0;
    long long low = 1, high = n;

    while(low <= high){
        long long mid = low + (high-low)/2;

        if(mid*mid <= n){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    int n = 28;

    cout << sqr_root(n) << endl;

    return 0;
}