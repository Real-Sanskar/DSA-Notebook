// Left rotate the array by one place

#include<bits/stdc++.h>
using namespace std;

// 1. Brute force apporach (using temp array)
// TC : O(N)  SC : O(N)

void left_rotate(vector<int> &arr){
    int n = arr.size();
    int temp[n];
    
    for(int i=1; i<n; i++){
        temp[i-1] = arr[i];
    }
    temp[n-1] = arr[0];

    cout << "Array after left rotate: ";
    for(int i=0; i<n; i++){
        cout << temp[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr = {1,2,3,4,5};

    left_rotate(arr);
}




// 2. Optimal approach
// TC : O(N)  SC : O(1)
// void left_rotate(vector<int> &arr){
//     int n = arr.size();
//     int temp = arr[0];
//     for(int i=0; i<n-1; i++){
//         arr[i] = arr[i+1];
//     }
//     arr[n-1] = temp;
// }

// int main(){
//     vector<int> arr = {1,2,3,4,5};

//     cout << "Array before left rotate: ";
//     for(auto val:arr){
//         cout << val << " ";
//     }
//     cout << endl;

//     left_rotate(arr);
    
//     cout << "Array after left rotate: ";
//     for(auto val:arr){
//         cout << val << " ";
//     }
//     cout << endl;


//     return 0;
// }