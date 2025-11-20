// given 2 sorted arrays of size m+n and n, 
// merge them into 1 sorted array inside arr1

#include<iostream>
#include<vector>
using namespace std;




// 3 pointer from back (TC : O(M+N)   SC : O(1))
// LOGIC : 
// use 3 pointers :
//      i = m-1 -> last valid element in nums1
//      j = n-1 -> last valid element in nums2
//      k = m+n-1 -> last index of nums1
// compare nums1[i] and nums2[j], place larger at nums1[k]
// move pointer accordingly
// If nums2 has element left, copy to nums1

void merge_arrays(vector<int> &arr1, int m, vector<int> &arr2, int n){
    int i = m-1, j=n-1, k = m+n-1;
    while(i >= 0 && j >= 0){
        if(arr1[i] >= arr2[j]){
            arr1[k] = arr1[i];
            i--, k--;
        }
        else{
            arr1[k] = arr2[j];
            j--, k--;
        }
    }
    while(j >= 0){
        arr1[k] = arr2[j];
        k--;
        j--;
    }
}

int main(){
    vector<int> arr1 = {-5,-2,4,5,0,0,0};
    vector<int> arr2 = {-3,1,8};
    int m = 4, n = 3;

    merge_arrays(arr1, m, arr2, n);

    for(auto val:arr1){
        cout << val << " ";
    }


    return 0;
}