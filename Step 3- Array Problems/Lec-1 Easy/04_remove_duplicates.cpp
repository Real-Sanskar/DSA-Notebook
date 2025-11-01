#include<iostream>
#include<set>
#include<vector>
using namespace std;


// // 1. Brute force method (creating set)
// // TC : O(N*log(N)) + O(N)   SC : O(N)

// int remove(vector<int> &arr, int n){
//     set<int> s;
//     for(int i=0; i<n; i++){
//         s.insert(arr[i]);
//     }

//     int k = s.size();
//     int j = 0;
//     for(auto val : s){
//         arr[j++] = val;
//     }

//     return k;
// }

int remove(vector<int> &arr, int n){
    if(arr.empty()) return 0;

    int i = 0;
    for(int j = 1; j<n; j++){
        if(arr[i] != arr[j]){
            i++;
            arr[i] = arr[j];
        }
    }

    return i + 1;
}

int main(){
    vector<int> arr = {1,1,2,2,3,3,3};
    int n = arr.size();

    int k = remove(arr,n);
    cout << "Array after removing the duplicates are: " << endl;

    for(int i=0; i<k; i++){
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}