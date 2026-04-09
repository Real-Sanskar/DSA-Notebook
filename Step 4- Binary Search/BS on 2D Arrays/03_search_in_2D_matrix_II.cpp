#include<bits/stdc++.h>
using namespace std;


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

bool findElement(vector<vector<int>> &mat, int key){
    int n = mat.size();
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