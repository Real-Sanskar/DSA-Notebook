#include<bits/stdc++.h>
using namespace std;


// 1. Brute force (TC : O(M*N)   SC : O(1))

// bool searchElement(vector<vector<int>> &mat, int key){
//     int n = mat.size();
//     int m = mat[0].size();
//     bool exist = false;

//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             if(mat[i][j] == key){
//                 exist = true;
//                 break;
//             }
//         }
//     }
//     return exist;
// }





// 2. Better approach (Binary search)   (TC : O(N) + O(logM)   SC: O(1))

// bool binarySearch(vector<int> &mat, int key){
//     int m = mat.size();
//     int low = 0, high = m-1;

//     while(low <= high){
//         int mid = low + (high - low)/2;

//         if(mat[mid] == key){
//             return true;
//         }
//         else if(key > mat[mid]){
//             low = mid + 1;
//         }
//         else{
//             high = mid - 1;
//         }
//     }
//     return false;
// }

// bool searchElement(vector<vector<int>> &mat, int key){
//     int n = mat.size();
//     int m = mat[0].size();

//     for(int i=0; i<n; i++){
//         if(mat[i][0] <= key && key <= mat[i][m-1]){
//             return binarySearch(mat[i],key);
//         }
//     }
//     return false;
// }




bool searchElement(vector<vector<int>> &mat, int key){
    int n = mat.size();
    int m = mat[0].size();

    int low = 0, high = (m*n - 1);

    while(low <= high){
        int mid = low + (high - low)/2;
        int row = mid / m;
        int col = mid % m;

        if(mat[row][col] == key){
            return true;
        }
        else if(mat[row][col] > key){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> mat = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int key = 9;

    if(searchElement(mat,key)){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
}