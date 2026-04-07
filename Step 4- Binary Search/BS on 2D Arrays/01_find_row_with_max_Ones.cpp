// Given a binary matrix, find row with maximum number of ones
// NOTE: Each row is sorted (0s before 1s)

#include<bits/stdc++.h>
using namespace std;



// 1. Brute force approach  (TC : O(N*M)   SC: O(1))

// for each row, count number of ones
// Track row with max ones
// return row index


// int findRow(vector<vector<int>> &mat, int n, int m){
//     int row = -1;
//     int maxCount = 0;

//     for(int i=0; i<n; i++){
//         int count = 0;
//         for(int j=0; j<m; j++){
//             if(mat[i][j] == 1){
//                 count++;
//             }
//         }
//         if(count > maxCount){
//             maxCount = count;
//             row = i;
//         }
//     }
//     return row;
// }





// 2. Better approach (Binary Search)    (TC : O(N*logM))

// for each row, use binary search to find the first occurance of 1
// count = m - (first index of 1)
// track maximum

// HELPER FUNCTION: Lower bound of 1 (first position where value >= 1)

// int lowerBound(vector<int> &mat, int m, int x){
//     int low = 0, high = m-1;
//     int ans = m;

//     while(low <= high){
//         int mid = low + (high-low)/2;

//         if(mid >= x){
//             ans = mid;
//             high = mid - 1;
//         }
//         else{
//             low = mid + 1;
//         }
//     }
//     return ans;
// }

// int findRow(vector<vector<int>> &mat, int n, int m){
//     int maxCount = 0;
//     int idx = -1;

//     for(int i=0; i<n; i++){
//         int count_ones = m - lowerBound(mat[i],m,1);
        
//         if(maxCount < count_ones){
//             maxCount = count_ones;
//             idx = i;
//         }
//     }
//     return idx;
// }





// 3. Optimized traversal  (TC: O(M+N)  SC : O(1))

// start from top right cell
// if current cell == 1: move left (earlier ones in this row)
// if current cell == 0: move down (no 1s before this in current row)
// TRACK ROW WITH LEFTMOST 1

int findRow(vector<vector<int>> &mat, int m, int n){
    int maxRow = -1;
    int i = 0, j = n-1;

    while(i<m && j>=0){
        if(mat[i][j] == 1){
            maxRow = i;
            j--;
        }
        else{
            i++;
        }
    }
    return maxRow;
}


int main(){
    vector<vector<int>> mat = {{1,1,1},{0,0,1},{0,0,0}};
    int n = mat.size();
    int m = mat[0].size();

    cout << findRow(mat,n,m) << endl; 
}