#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int> nums){
    for(auto val : nums){
        cout << val << " ";
    }
    cout << endl;
}

void insertionSort(vector<int> &nums, int n, int i){
    if(i == n) return;

    int temp = nums[i];
    int j=i-1;
    while(j>=0 && nums[j] > temp){
        nums[j+1] = nums[j];
        j--;
    }
    nums[j+1] = temp;

    insertionSort(nums, n , i+1);

}

int main(){
    vector<int> nums = {4,6,9,1,5,2};
    int n = nums.size();

    printArray(nums);
    insertionSort(nums, n , 1);
    printArray(nums);

    return 0;
}