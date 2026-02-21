// given two numbers n, m, Find nth root of m
// nth root of m, is a number X such that : x^n = m
// if no perfect root, return -1

#include<iostream>
#include<math.h>
using namespace std;


// Linear search (TC : O(M))
// Logic: Try all numbers from 1 to M, check if i^N = M
// Algorithm:
// For i from 1 to M:
// If i^N == M: return i
// If i^N > M: break (no point checking further)
// Return -1

// int nthRoot(int n, int m){
//     for(int i=1; i<=m; i++){
//         long long power = pow(i,n);

//         if(power == m){
//             return i;
//         }

//         if(power > m){
//             break;
//         }
//     }
//     return -1;
// }





// Binary Search : TC : O(logM)
// Logic: Binary search on answer space (1 to M)

// Helper Function: Calculate mid^N with overflow handling


long long power(int mid, int n, int m){
    long long result = 1;
    for(int i=1; i<=n; i++){
        result *= mid;
        
        if(result > m) break;
    }
    return result;
}

int nthRoot(int n, int m){
    int low = 1, high = m;
    
    while(low <= high){
        int mid = low + (high-low)/2;
        long long ans = power(mid,n,m);

        if(ans == m){
            return mid;
        }
        else if(ans < m){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    int n = 3, m = 27;

    cout << nthRoot(n,m) << endl;

    return 0;
}