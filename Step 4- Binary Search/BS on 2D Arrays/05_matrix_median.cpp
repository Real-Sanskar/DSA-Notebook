// Problem: Find median of row-wise sorted matrix
// Given: N×M matrix where each row is sorted (N and M are odd)
// Median: Middle element when all elements arranged in sorted order

#include<bits/stdc++.h>
using namespace std;


// 1. Brute force (TC : O(N*M + N*M*log(N*M))    SC : O(N*M))

// Logic: Store all elements, sort, return middle

// int findMedian(vector<vector<int>> &mat){
//     int n = mat.size();
//     int m = mat[0].size();
//     vector<int> temp;
//     int size = m*n;

//     for(auto row : mat){
//         for(int val : row){
//             temp.push_back(val);
//         }
//     }
//     sort(temp.begin(),temp.end());

//     return temp[(size-1)/2];

// }





// 2. Optimal approach (TC : O(N*M*log(N*M)))

// Logic: Binary search on value range, count elements ≤ mid
// Key Observation:

// Median has (n×m)/2 elements smaller than it
// Binary search on value: min(matrix) to max(matrix)
// For each value, count how many elements ≤ value
// Find smallest value with count > (n×m)/2


int upperBound(vector<int> &arr, int m, int x){
    int low = 0;
    int high = m-1;
    int ans = m;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(arr[mid] <= x){
            low = mid + 1;
        }
        else{
            ans = mid;
            high = low - 1;
        }
    }
    return ans;
}

int countSmallEqual(vector<vector<int>> &mat, int n, int m, int x){
    int cnt = 0;
    for(int i=0; i<n; i++){
        cnt += upperBound(mat[i], m, x);
    }
    return cnt;
}

int findMedian(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();

    int low = INT_MAX, high = INT_MIN;
    for(int i=0; i<n; i++){
        low = min(low,mat[i][0]);
        high = max(high, mat[i][m-1]);
    }

    int req = (m*n)/2;
    while(low <= high){
        int mid = low + (high-low)/2;
        int smallEqual = countSmallEqual(mat, n, m, mid);

        if(smallEqual <= req){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
}

int main(){
    vector<vector<int>> mat = {
        {1,4,9},
        {2,5,6},
        {3,8,7}
    };

    cout << findMedian(mat) << endl;
}