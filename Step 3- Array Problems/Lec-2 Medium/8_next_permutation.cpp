// given an array, rearrange numbers to give 
// lexicographically next greater permutation

// IF next permutation not possible return lowest permutation

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// 1. Brute force (TC : O(N*N!)   SC: O(N*N!))
// Generate all permutations using next_permutation()
// Store in vector of vectors
// find current permutation , return next one
// if current is last permutation, return first

// vector<int> nextPermutation(vector<int> &arr){
//     vector<int> original = arr;
//     vector<vector<int>> all ;

//     sort(arr.begin(),arr.end());
//     do{
//         all.push_back(arr);
//     }while(next_permutation(arr.begin(),arr.end()));

//     for(int i=0; i < all.size(); i++){
//         if(all[i] == original){
//             if(i == all.size()-1){
//                 return all[0];
//             }

//             return all[i+1];
//         }
//     }
// }



// 2. Optimal approach (TC : O(N)    SC : O(1))
// Find breakpoint : first i such that arr[i-1] < arr[i] (from right)
// if no breakpoint reverse array
// find smallest element > arr[pivot] (from right)
// swap that element with pivot
// reverse array from pivot + 1 to n-1

vector<int> nextPermutation(vector<int> arr){
    int n = arr.size();

    int pivot = -1;
    for(int i=n-1; i>=1; i--){
        if(arr[i-1] < arr[i]){
            pivot = i-1;
            break;
        }
    }
    if(pivot == -1){
        reverse(arr.begin(),arr.end());
    }
    for(int i=n-1; i> pivot; i--){
        if(arr[i] > arr[pivot]){
            swap(arr[pivot],arr[i]);
            break;
        }
    }
    int i= pivot +1, j = n-1;
    while(i <= j){
        swap(arr[i],arr[j]);
        i++, j--;
    }

    return arr;
}

int main(){
    vector<int> arr = {1,3,2};

    vector<int> ans = nextPermutation(arr);

    cout << "Next permutation is : " << endl;
    for(auto val : ans){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}