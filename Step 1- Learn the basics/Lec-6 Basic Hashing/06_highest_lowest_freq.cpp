// Given an array of size N, Find the highest and lowest frequency element

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// // 1. Using 2 for loops
// void countFreq(int arr[], int n){
//     vector<bool> visited(n,false);

//     int max_freq = 0, min_freq = n;
//     int max_ele = 0, min_ele = 0;
    
//     for(int i=0; i<n; i++){
//         if(visited[i] == true){
//             continue;
//         }
//         visited[i] = true;
//         int count = 1;
//         for(int j=i+1; j<n; j++){
//             if(arr[i] == arr[j]){
//                 count++;
//                 visited[j] = true;
//             }
//         }
//         if(count > max_freq){
//             max_freq = count;
//             max_ele = arr[i];
//         }
//         if(count < min_freq){
//             min_freq = count;
//             min_ele = arr[i];
//         }

//     }
//     cout << max_ele << " " << min_ele << endl;
// }

// 2. Using map
void countFreq(int arr[], int n){
    unordered_map<int,int> m;

    for(int i=0; i<n; i++){
        m[arr[i]]++;
    }

    int max_freq = 0, min_freq = n;
    int max_ele = 0, min_ele = 0;

    for(auto val:m){
        int count = val.second;
        int element = val.first;

        if(count > max_freq){
            max_freq = count;
            max_ele = element;
        }
        if(count < min_freq){
            min_freq = count;
            min_ele = element;
        }
    }
    cout << max_ele << " " << min_ele << endl;
}

int main(){
    int arr[] = {10,5,10,15,10,5};
    int n = 6;

    countFreq(arr,n);

    return 0;
}