#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int> &nums){
    for(auto val:nums){
        cout << val << " ";
    }
    cout << endl;
}


// TC : O(N*N)   SC : O(1)
vector<int> insertionSort(vector<int> &nums){
    int n = nums.size();
    for(int i=1; i<n; i++){
        int temp = nums[i];
        int j = i-1;
        while(j>=0 && temp < nums[j]){
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = temp;
    }
    return nums;
}

int main(){
    vector<int> nums = {4,6,9,1,5,2};

    printArray(nums);

    nums = insertionSort(nums);
    
    printArray(nums);

    return 0;
}

