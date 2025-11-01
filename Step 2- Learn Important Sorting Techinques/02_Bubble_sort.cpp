#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int> nums){
    for(auto val:nums){
        cout << val << " ";
    }
    cout << endl;
}

// // 1. Brute force way      TC : O(N*N)   SC : O(1)
// vector<int> bubbleSort(vector<int> &nums){
//     int n = nums.size();
//     for(int i=0; i<n-1; i++){ 
//         for(int j=0; j<n-1-i; j++){
//             if(nums[j] > nums[j+1]){
//                 swap(nums[j], nums[j+1]);
//             }
//         }
//     }
//     return nums;
// }

// 2. Optimal way (Reduce TC to O(N) for best case, if array is already sorted)
vector<int> bubbleSort(vector<int> &nums){
    int n= nums.size();
    for(int i=0; i<n-1; i++){
        bool isSwaped = false;
        for(int j=0; j< n-1-i; j++){
            if(nums[j] > nums[j+1]){
                swap(nums[j],nums[j+1]);
                isSwaped = true;
            }
        }
        if(!isSwaped){
            return nums;
        }

    }
    return nums;
}

int main(){
    vector<int> nums = {4,6,9,1,5,2};

    printArray(nums);

    nums = bubbleSort(nums);
    
    printArray(nums);

    return 0;
}