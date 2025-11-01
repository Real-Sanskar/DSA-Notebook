#include<iostream>
#include<vector>
using namespace std;

// 1. Brute force approach (Using extra array)
// TC : O(N)   SC : O(N)

// void move_zero(vector<int> &arr){
//     int n = arr.size();

//     vector<int> temp;

//     for(int i=0; i<n; i++){
//         if(arr[i] != 0){
//             temp.push_back(arr[i]);
//         }
//     }

//     int m = temp.size();
//     for(int i=0; i<m; i++){
//         arr[i] = temp[i];
//     }

//     for(int i = m; i<n; i++){
//         arr[i] = 0;
//     }

//     cout << "Array after moving 0s to the end: ";
//     for(auto val: arr){
//         cout << val << " ";
//     }
//     cout << endl;
// }


// 2. Better Apporoach (swaping)
// TC : O(N)   SC : O(1)
// swaps elements even when i = j , example : [1,2,3,4,5], no need of swapping, still it swaps
// Taking more operations

// void move_zero(vector<int> &arr){
//     int n = arr.size();

//     int i = 0; // tracks position where next non-zero element should go
//     int j=0; // Scans the array

//     for(j = 0; j<n; j++){
//         if(arr[j] != 0){
//             swap(arr[i],arr[j]);
//             i++;
//         }
//     }

//     cout << "Array after moving 0s to the end: ";
//     for(auto val : arr){
//         cout << val << " ";
//     }
//     cout << endl;
// }

// 3. Optimized (writing non-zero elements to right)
// Each non-zero element is written only once, reducing no. of operations

void move_zero(vector<int> &arr){
    int n = arr.size();
    
    int i = 0;

    // Step-1: Move all non-zero elements to front
    for(int j=0; j<n; j++){
        if(arr[j] != 0){
            arr[i] = arr[j];
            i++;
        }
    }

    // Step-2: Fill remaining positions with 0s
    while(i<n){
        arr[i] = 0;
        i++;
    }

    cout << "Array after moving zeros to end: ";
    for(auto val : arr){
        cout << val << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr = {1,2,0,1,0,4,0};

    move_zero(arr);

    return 0;
}