// Count frequency of each element in array

// We are give an array, we have to find the number of occurrence of each element

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


// // 1. Two loops -> TC: O(N*N), SC: O(N)
// void count_frequency(int arr[], int n){
//     // Create a vector of size n and type bool , and initialize it with false
//     vector<bool> visited(n,false);
    
//     // Outer loop point an element of array
//     for(int i=0; i<n; i++){
//         if(visited[i] == true){  // If visited is true then skip to next iteration
//             continue;
//         }
//         visited[i] = true; // Else make visited[i] true

//         int count = 1; // Initialize count
    
//         // Inner loop pointing an element
//         for(int j=i+1; j<n; j++){ 
//             // If same element found make index true and increase count
//             if(arr[i] == arr[j]){
//                 visited[j] = true;
//                 count++;
//             }
//         }
//         // Print the result
//         cout << arr[i] << " " << count << endl;

//     }

// }

// 2. Using map
void count_frequency(int arr[], int n){
    unordered_map<int,int> m;
    for(int i=0; i<n; i++){
        m[arr[i]] += 1;
    }

    for(auto val:m){
        cout << val.first << " " << val.second << endl;
    }
}


int main(){
    int arr[] = {10,5,10,15,10,5};
    int n = 6;

    count_frequency(arr,n);

    return 0;
}