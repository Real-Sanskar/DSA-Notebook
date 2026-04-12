// Find peak element in 2D array
// PEAK ELEMENT: element greater than all neighbours (left,right,top,bottom)
// NOTE: Multiple peaks may exists, return any one index

#include<bits/stdc++.h>
using namespace std;



// 1. Brute force approach (TC : O(N*M))

// for each element compare with all of its neighbours
// if element > all neighbours, return position


// bool isPeak(vector<vector<int>> &mat, int i, int j){
//     int n = mat.size();
//     int m = mat[0].size();
//     int val = mat[i][j];

//     if(i>0 && mat[i-1][j] > val) return false;
//     if(i<n-1 && mat[i+1][j] > val) return false;
//     if(j>0 && mat[i][j-1] > val) return false;
//     if(j<m-1 && mat[i][j+1] > val) return false;

//     return true;
// }

// vector<int> peak_element(vector<vector<int>> &mat){
//     int n = mat.size();
//     int m = mat[0].size();
    
//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             if(isPeak(mat,i,j)){
//                 return {i,j};
//             }
//         }
//     }
//     return {-1,-1};
// }




// 2. Optimal approach (BS ON COLUMNS) (TC : O(N*logM))

// 1. Find MAX in middle column
//    → Max already beats TOP and BOTTOM neighbours
//    → Only need to check LEFT and RIGHT!

// 2. If LEFT > current → peak exists in LEFT half
//    If RIGHT > current → peak exists in RIGHT half
//    Both < current → PEAK FOUND!

// 3. Why moving toward larger neighbour guarantees peak?
//    → Eventually hits -1 boundary
//    → Element just before boundary MUST be a peak
//    → Peak always exists in that direction!


int maxElement(vector<vector<int>> &mat, int mid){
    int n = mat.size();
    int max=-1, idx=-1;

    for(int i=0; i<n; i++){
        if(mat[i][mid] > max){
            max = mat[i][mid];
            idx = i;
        }
    }
    return idx;
}

vector<int> peak_element(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();
    int low = 0, high = m-1;

    while(low <= high){
        int mid = low + (high-low)/2;
        int row = maxElement(mat,mid);
        
        int left = (mid-1) > 0? mat[row][mid-1] : -1;
        int right = (mid+1) < m? mat[row][mid+1] : -1;

        if(mat[row][mid] > left && mat[row][mid] > right){
            return {row,mid};
        }
        else if(mat[row][mid] < left){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return {-1,-1};
}

int main(){
    vector<vector<int>> mat = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    vector<int> ans = peak_element(mat);
    for(auto val: ans){
        cout << val << " ";
    }
}