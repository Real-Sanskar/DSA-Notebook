// Problem : count inversion in array (pairs i<j, arr[i] > arr[j])


#include<iostream>
#include<vector>
using namespace std;


// 1. Brute force approach (TC : O(N*N)   SC : O(1))
// - Use two nested loops to check all pairs.
// - Not efficient for large arrays.


// int count_inversion(vector<int> &arr){
//     int n = arr.size();

//     int count = 0;
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             if(arr[j] < arr[i]){
//                 count++;
//             }
//         }
//     }
//     return count;
// }



// 2. Optimal approach (Modified merge sort)  (TC : O(N*logN)    SC : O(N))

// - Use divide and conquer like merge sort.
// - While merging two halves, count how many elements from left half
//   are greater than elements in right half.
// - Add this count to total inversions.

// - Efficient and widely accepted solution.



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
            count += (mid-left+1);
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

    for(int i = low; i <= high; i++){
        arr[i] = temp[i-low];
    }

    return count;
}

int merge_sort(vector<int> &arr, int low, int high){
    int count = 0;
    if(low < high){
        int mid = low + (high-low)/2;
        count += merge_sort(arr,low,mid);
        count += merge_sort(arr,mid+1,high);
        count += merge(arr,low,mid,high);
    }
    return count;
}

int count_inversion(vector<int> &arr){
    int n = arr.size();

    return merge_sort(arr,0,n-1);
}

int main(){
    vector<int> arr = {5,3,2,1,4};

    cout << count_inversion(arr) << endl;

    return 0;
}