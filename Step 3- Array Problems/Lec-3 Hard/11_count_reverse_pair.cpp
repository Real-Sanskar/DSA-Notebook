// Given an array of size n, count pairs (i,j), where i<j and (arr[i] > 2 * arr[j])

#include<iostream>
#include<vector>
using namespace std;



// 1. Brute force approach (TC : O(N*N)   SC : O(1))
// LOGIC : check all pairs(i,j) with nested loops

// int reverse_pair(vector<int> &arr){
//     int n = arr.size();

//     int count = 0;
//     for(int i=0; i<n; i++){
//         for(int j=i; j<n; j++){
//             if(arr[i] > (2 * arr[j])){
//                 count++;
//             }
//         }
//     }
//     return count;
// }





// 2. Optimal approach (TC : O(N*logN)    SC : O(N))
// LOGIC : 
// use divide and conquer
// Recursively count pairs in left and right
// count cross pairs (left element > 2 * right element)
// merge sorted half   

int merge(vector<int> &arr, int low, int mid, int high){
    int left = low;
    int right = mid+1;

    vector<int> temp;
    int count = 0;

    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }

    return count;
}

int count_pair(vector<int> &arr, int low, int mid, int high){
    int count = 0, right = mid+1;

    for(int i=low; i<=mid; i++){
        while(right <= high && arr[i] > 2 * arr[right]){
            right++;
        }
        count += (right - (mid+1));
    }
    return count;
}

int merge_sort(vector<int> &arr, int low, int high){
    int count = 0;
    if(low < high){
        int mid = low + (high-low)/2;

        count += merge_sort(arr,low,mid);
        count += merge_sort(arr,mid+1,high);
        count += count_pair(arr,low,mid,high);

        merge(arr,low,mid,high);
    }
    return count;
}

int reverse_pair(vector<int> &arr){
    int n = arr.size();

    return merge_sort(arr,0,n-1);
}

int main(){
    vector<int> arr = {1,3,2,3,1};

    cout << reverse_pair(arr) << endl;

    return 0;
}