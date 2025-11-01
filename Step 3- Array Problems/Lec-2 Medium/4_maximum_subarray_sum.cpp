// Given an array, find subarray which has largest sum and return sum

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// 1. Brute force appproach (Using 3 loops)
// loop-1 : starting index of subarray
// loop-2 : ending index of subarray
// loop-3 : calculate sum of subarray
// return the maximum sum

// int max_sum(vector<int> &arr){
//     int n = arr.size();

//     int maxSum = INT_MIN;
//     for(int i=0; i<n; i++){
//         for(int j=i; j<n; j++){
//             int currSum = 0;
//             for(int k=i; k<=j; k++){
//                 currSum += arr[k];
//             }
//             maxSum = max(maxSum,currSum);
//         }
//     }
//     return maxSum;
// }



// 2. Optimized Brute force approach (2 loops)
// loop-1 : starting of subarray
// loop-2 : ending of a subarray, calcuate curr sum and compare with maxSum

// TC : O(N*N)    SC : O(N)

// int max_sum(vector<int> &arr){
//     int n = arr.size();

//     int maxSum = INT_MIN;
//     for(int i=0; i<n; i++){
//         int currSum = 0;
//         for(int j=i; j<n; j++){
//             currSum += arr[j];

//             maxSum = max(maxSum,currSum);
//         }
//     }
//     return maxSum;
// }



// Optimal (Kadyne's algorithm)
// LOGIC : if sum < 0 -> can't be greatest subarray, make sum=0

// Iterater -> 0 to n-1
// caculate subarray currSum, compare with maxSum and add store in it
// if currSum < 0 : currSum = 0;


// int max_sum(vector<int> &arr){
//     int n = arr.size();

//     int maxSum = INT_MIN, currSum = 0;
//     for(int i=0; i<n; i++){
//         currSum += arr[i];

//         if(currSum > maxSum){
//             maxSum = currSum;
//         }
//         if(currSum < 0){
//             currSum = 0;
//         }
//     }
//     // To consider the sum of an empty subarray, uncomment
//     // if(maxSum < 0) maxSum = 0;


//     return maxSum;
// }



// WHY? = if multiple subarray have same sum, print any one of them

int max_sum(vector<int> &arr){
    int n = arr.size();
    int start = 0;
    int ansStart = -1, ansEnd = -1;


    int currSum = 0, maxSum = INT_MIN;
    for(int i=0; i<n; i++){
        if(currSum == 0) start = i;

        currSum += arr[i];

        if(currSum > maxSum){
            maxSum = currSum;

            ansStart = start;
            ansEnd = i;
        }

        if(currSum < 0) currSum = 0;
    }
    cout << "Subarray is : " << endl;
    for(int i = ansStart; i<= ansEnd; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return maxSum;
}

int main(){
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};

    cout << max_sum(arr) << endl;

    return 0;
}