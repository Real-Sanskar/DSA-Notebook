#include<bits/stdc++.h>
using namespace std;


void helper(int i, int n, vector<int>& arr, vector<vector<int>>& ans, vector<int>& curr, int remaining){
    if(remaining == 0){
        ans.push_back(curr);
        return;
    }

    if(i >= n || remaining < 0) return;

    if(remaining >= arr[i]){
        curr.push_back(arr[i]);
        helper(i, n, arr, ans, curr, (remaining - arr[i]));
        curr.pop_back();
    }
    helper(i+1, n, arr, ans, curr, remaining);
}

vector<vector<int>> combinationSum(vector<int>& arr, int target){
    int n = arr.size();

    vector<vector<int>> ans;
    vector<int> curr;

    helper(0, n, arr, ans, curr, target);

    return ans;
}

int main(){
    vector<int> arr = {2,3,5,4};
    int target = 7;


    vector<vector<int>> ans = combinationSum(arr, target);

    for(auto& z: ans){
        for(auto& val: z){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}