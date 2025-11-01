// Given an array and an integer target, return 2 number whose sum is equal to target
// Return -1,-1  otherwise

// 2 VARIANTS : 
// 1. RETURN YES OR NO
// 2. RETURN INDICES

#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;


// 1. Brute force approach (Using 2 loops)
// loop-1 : picks an element in the array
// loop-2 : picks other element and try to find sum = target

// TC : O(N*N)    SC: O(1)

// ** APPLICABLE FOR BOTH VARIANTS **

// pair<int,int> Two_sum(vector<int> &arr, int target){
//     int n = arr.size();

//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             if(arr[i] + arr[j] == target){
//                 return {i,j};
//             }
//         }
//     }
//     return {-1,-1};
// }



// 2. Better approach (HashMap)
// stores elements of array in map
// pick an element in array and find second element in map
// if found return both indices

// TC : O(N)   SC : O(N)

// ** APPLICABLE FOR BOTH VARIANTS **

// pair<int,int> Two_sum(vector<int> &arr, int target){
//     int n = arr.size();
//     unordered_map<int,int> temp;

//     // pre-storing
//     for(int i=0; i<n; i++){
//         temp[arr[i]] = i;
//     }

//     // Fetching
//     for(int i=0; i<n; i++){
//         int ele = target - arr[i];

//         if(temp.find(ele) != temp.end()){
//             return {i,temp[ele]};
//         }
//     }
//     return {-1,-1};

// }



// 3. Optimal (2 pointer approach)

// TC : O(N) + O(N*log(N))    SC : O(1)

// ** APPLICABLE FOR ONLY YES/ NO VARIANT **
// ** REASON : loss of indices due to sorting

string Two_sum(vector<int> &arr, int target){
    int n = arr.size();

    sort(arr.begin(),arr.end());
    int left = arr.front(), right = arr.back();
    int sum = 0;

    while(left < right){
        sum = arr[left] + arr[right];

        if(sum == target){
            return "YES";
        }
        else if(sum > target){
            right--;
        }
        else{
            left++;
        }
    }
    return "NO";
}


int main(){
    vector<int> arr = {2,6,5,8,11};
    int target = 14;

    
    // FOR 1 AND 2
    // pair<int,int> result = Two_sum(arr,target);

    // cout << result.first << " " << result.second << endl;


    // FOR 3

    cout << Two_sum(arr,target);
    return 0;
}