// Search target in a 2D matrix where:
// Each row is sorted
// first element of each row NOT NECESSARILY greater than last element of previous row

#include<bits/stdc++.h>
using namespace std;



// 1. Brute force approach (TC : O(N*M)   SC : O(1))

// Traverse entire matrix
// If found return true, else return false


// bool findElement(vector<vector<int>> &mat, int key){
//     int n = mat.size();
//     int m = mat[0].size();
    
//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             if(mat[i][j] == key) return true;
//         }
//     }
//     return false;
// }





// 2. Better approach (Binary Search)  (TC : O(N + logM)   SC : O(1))

// Find row where target may exists
// Binary search in that row to find position


// bool binarySearch(vector<int> &mat, int key){
//     int m = mat.size();
//     int low = 0, high = m-1;

//     while(low<=high){
//         int mid = low + (high-low)/2;

//         if(mat[mid] == key) return true;
//         else if(mat[mid] > key) high = mid - 1;
//         else low = mid + 1;
//     }
//     return false;
// }

// bool findElement(vector<vector<int>> &mat, int key){
//     int n = mat.size();
//     int m = mat[0].size();

//     for(int i=0; i<n; i++){
//         if(mat[i][0] <= key && key <= mat[i][m-1]){
//             return binarySearch(mat[i],key);
//         }
//     }
//     return false;
// }




// 3. Optimal approach (TC : O(M+N)   SC : O(1))

// TOP-RIGHT (row=0, col=m-1):
//   • LARGEST in its ROW (row is sorted left to right)
//   • SMALLEST in its COLUMN (column is sorted top to bottom)

// BOTTOM-LEFT (row=n-1, col=0):
//   • SMALLEST in its ROW
//   • LARGEST in its COLUMN


bool findElement(vector<vector<int>> &mat, int key){
    int n = mat.size();
    int m = mat[0].size();
    
    int i = 0, j = m-1;
    while(i<n && j>=0){
        if(mat[i][j]==key){
            return true;
        }
        else if(mat[i][j] < key){
            i++;
        }
        else{
            j--;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> mat = {{1,4,7,11},{2,5,8,12},{3,6,9,16},{10,13,14,17}};
    int key = 12;

    if(findElement(mat,key)){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    return 0;
}