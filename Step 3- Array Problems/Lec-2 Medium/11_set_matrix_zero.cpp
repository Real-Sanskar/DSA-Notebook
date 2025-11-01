// Given a matrix, if an element of matrix is 0, make its rows and columns to 0
// Return matrix

#include<iostream>
#include<vector>
using namespace std;


// 1. Brute force approach (TC : O(M*N*(M+N)) + O(M*N)        SC : O(1))

// Traverse matrix
// If any element is 0, mark all rows and cols with placeholder (-1 ) ** DO NOT MARK CHANGE MARK 0 AS -1 **
// SECOND PASS : convert all -1 to 0


// vector<vector<int>> matrixZero(vector<vector<int>> arr){
//     int m = arr.size();
//     int n = arr[0].size();

//     for(int i=0; i<m; i++){
//         for(int j=0; j<n; j++){
//             if(arr[i][j] == 0){
//                 for(int k=0; k<m; k++){
//                     if(arr[k][j] != 0){
//                         arr[k][j] = -1;
//                     }
//                 }
//                 for(int k=0; k<n; k++){
//                     if(arr[i][k] != 0){
//                         arr[i][k] = -1;
//                     }
//                 }
//             }
//         }
//     }

//     for(int i=0; i<m; i++){
//         for(int j=0; j<n; j++){
//             if(arr[i][j] == -1){
//                 arr[i][j] = 0;
//             }
//         }
//     }
//     return arr;
// }



// 2. Better approach (TC : O(2*(M*N))    SC : O(M) + O(N))
// LOGIC : Use separate array to track which row/col needs to 0
// ALGORITHM: 
// Create row[m] and col[n], initialize with 0
// Traverse matrix, if cell = 0, mark row[i] , col[j] to 0
// second pass : mark cell to 0 where row or col marked to 1


// vector<vector<int>> matrixZero(vector<vector<int>> &arr){
//     int m = arr.size();
//     int n = arr[0].size();

//     vector<int> row(m,0);
//     vector<int> col(n,0);

//     for(int i=0; i<m; i++){
//         for(int j=0; j<n; j++){
//             if(arr[i][j] == 0){
//                 row[i] = 1;
//                 col[j] = 1;
//             }
//         }
//     }
//     for(int i=0; i<m; i++){
//         for(int j=0; j<n; j++){
//             if(row[i] == 1 || col[j] == 1){
//                 arr[i][j] = 0;
//             }
//         }
//     }
//     return arr;
// }



// 3. Optimal approach (TC : O(2*(M*N))    SC : O(1))
// LOGIC : 
// Use first row and first column as markers instead of extra arrays 
// Track col0 seperately for first column
// First pass : mark rows/cols
// Second pass : mark cells to 0 , if either row or column is marked 0
// Third pass : 0 first row/col based on markers 

vector<vector<int>> matrixZero(vector<vector<int>> arr){
    // row[m] = {0} => arr[..][0]
    // col[n] = {0} => arr[0][..]

    int m = arr.size();
    int n = arr[0].size();

    int col0 = 1;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 0){
                arr[i][0] = 0;

                if(j!=0){
                    arr[0][j] = 0;
                }
                else{
                    col0 = 0;
                }
            }
        }
    }

    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(arr[i][0] == 0 || arr[0][j] == 0){
                arr[i][j] = 0;
            }
        }
    }

    if(arr[0][0] == 0){
        for(int i=0; i<n; i++){
            arr[0][i] = 0;
        }
    }
    if(col0 == 0){
        for(int i=0; i<m; i++){
            arr[i][0] = 0;
        }
    }
    return arr;
}

int main(){
    vector<vector<int>> arr = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};

    arr = matrixZero(arr);

    for(auto val : arr){
        for(auto it : val){
            cout << it << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}