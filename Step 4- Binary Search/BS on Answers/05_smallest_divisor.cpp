// Given an array and an integer limit, find smallest positive integer divisor, such that on dividing all array
// elements, the sum of elements is less than threshold or limit

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;




// Linear Search (TC : O(max(arr) * N))
// Logic: Try divisors from 1 to max(arr), find minimum valid
// Algorithm:

// For divisor from 1 to max(arr):

// Calculate sum of divisions
// If sum ≤ limit: return divisor

long long sumOfDivision(vector<int> &arr, int d){
    long long sum = 0;
    for(int val: arr){
        sum += (val + d - 1)/d;
    }
    return sum;
}

// int smallestDivisor(vector<int> &arr, int limit){
//     int maxVal = *max_element(arr.begin(),arr.end());
//     for(int i=1; i<=maxVal; i++){
//         long long result = sumOfDivision(arr,i);

//         if(result <= limit){
//             return i;
//         }
//     }
//     return -1;
// }





// Linear search (TC : O(log(max(arr)) * N))
// Logic: Binary search on divisor value
// Key Observation:

// Larger divisor → smaller division results → smaller sum
// If divisor X works, divisor X+1 also works
// Monotonic property (decreasing sum with increasing divisor)
// Find minimum divisor that satisfies condition

int smallestDivisor(vector<int> &arr, int limit){
    int low = 1, high = *max_element(arr.begin(),arr.end());

    while(low <= high){
        int mid = low + (high-low)/2;
        long long sum = sumOfDivision(arr, mid);  // Helper function

        if(sum <= limit){
            high = mid - 1;
        }
        else{
            low  = mid + 1;
        }
    }
    return low;
}


int main(){
    vector<int> arr = {1,2,5,9};
    int limit = 6;

    cout << smallestDivisor(arr, limit) << endl;

    return 0;
}