#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int> nums){
    for(auto val:nums){
        cout << val << " ";
    }
    cout << endl;
}

// TC : O(N*N)   SC : O(1)
vector<int> selectionSort(vector<int> &nums){
    int n = nums.size();
    for(int i=0; i<n-1; i++){
        int smallestIdx = i;
        for(int j=i+1; j<n; j++){
            if(nums[j] < nums[smallestIdx]){
                smallestIdx = j;
            }
        }
        swap(nums[smallestIdx], nums[i]);
    }
    return nums;
}

int main(){
    vector<int> nums = {4,6,9,1,5,2};

    printArray(nums);

    nums = selectionSort(nums);
    
    printArray(nums);


    return 0;
}