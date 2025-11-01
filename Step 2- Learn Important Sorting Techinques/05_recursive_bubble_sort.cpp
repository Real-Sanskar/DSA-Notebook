#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int> nums){
    for(auto val : nums){
        cout << val << " ";
    }
    cout << endl;
}

// // 1. First approach -> TC : O(N*N)  SC : O(N)
// void recursiveBubble(vector<int> &nums, int n){
//     if(n==1) return ;

//     for(int i=0; i<n; i++){
//         if(nums[i] > nums[i+1]){
//             swap(nums[i],nums[i+1]);
//         }
//     }
//     recursiveBubble(nums, n-1);
// }


// 2. Optimal approach (for best cases) 
// TC : O(N*N) for worst case
//      O(N) for best case
// SC : O(N)
void recursiveBubble(vector<int> &nums, int n){
    if(n==1) return;

    bool isSwapped = false;
    for(int i=0; i<n-1; i++){
        if(nums[i] > nums[i+1]){
            swap(nums[i], nums[i+1]);
            isSwapped = true;
        }
    }

    if(!isSwapped){
        return;
    }

    recursiveBubble(nums, n-1);
}


int main(){
    vector<int> nums = {4,6,9,1,5,2};

    int n= nums.size();

    printArray(nums);
    recursiveBubble(nums, n);
    printArray(nums);

    return 0;
}