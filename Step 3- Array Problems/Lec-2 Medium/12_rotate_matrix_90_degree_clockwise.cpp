// Give a matrix, rotate it by 90 degree clockwise

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



// 1. Brute force approach (TC : O(N*N)   SC : O(N*N))

// LOGIC : 
// create a dummy vector of size n*n
// Traverse over matrix 
// Store first row in last column and so on 
// formula : arr[j][n-i-1] = arr[i][j]

// vector<vector<int>> rotate_matrix(vector<vector<int>> &arr){
//     int n = arr.size();

//     vector<vector<int>> rotated(n, vector<int>(n,0));
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             rotated[j][n-i-1] = arr[i][j];
//         }
//     }

//     return rotated;
// }




// 2. Optimal approach (TC : O(N*N)    SC : O(1))
// LOGIC : IN-PLACE
// Transpose matrix : swap(arr[i][j],arr[j][i])  ** Avoid swaping same elements more than once **
// Reverse every row of matrix : reverse(arr[i].begin(),arr[i].end);


// DRY RUN : 
// Input : {{1,2,3},
//          {4,5,6},
//          {7,8,9}}

// Output: {{7,4,1},
//          {8,5,2},
//          {9,6,3}}

vector<vector<int>> rotate_matrix(vector<vector<int>> arr){
    int m = arr.size();
    int n = arr[0].size();

    // Transpose matrix
    for(int i=0; i<m; i++){
        for(int j=i+1; j<n; j++){
            swap(arr[i][j],arr[j][i]);
        }
    }

    // Reverse each row
    for(int i=0; i<m; i++){
        reverse(arr[i].begin(),arr[i].end());
    }

    return arr;
}

int main(){
    vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};

    vector<vector<int>> rotated = rotate_matrix(arr);

    for(auto val : rotated){
        for(auto it : val){
            cout << it << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}