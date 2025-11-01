// Optimal method (Reversal algorithm)

#include<bits/stdc++.h>
using namespace std;

void Reverse(vector<int> &arr, int low, int high){
    int temp;
    while(low<=high){
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;

        low++;
        high--;
    }
}

// 1. left rotate
void left_rotate(vector<int> &arr, int k){
    int n = arr.size();

     k = k % n;

    // Step-1: Reverse first k elements
    Reverse(arr, 0, k-1);

    // Step-2: Reverse last n-k elements
    Reverse(arr, k, n-1);

    // Step-3: Reverse whole array
    Reverse(arr, 0, n-1);

    cout << "Array after rotating elements to left by k elements: ";
    
    for(int val: arr){
        cout << val << " ";
    }
    cout << endl;

}


// 2. For right rotate
void right_rotate(vector<int> &arr, int k){
    int n = arr.size();

    k = k % n;

    // Step-1: Reverse last k elements
    Reverse(arr, n-k, n-1);

    // Step-2: Reverse first n-k elements
    Reverse(arr, 0, n-k-1);

    // Step-3: Reverse whole array
    Reverse(arr, 0, n-1);

    cout << "Array after right rotating the array by k elements: ";

    for(auto val : arr){
        cout << val << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    int k = 7;

    left_rotate(arr,k);

    // right_rotate(arr,k);

    return 0;
}