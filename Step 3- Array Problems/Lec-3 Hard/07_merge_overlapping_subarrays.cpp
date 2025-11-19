#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// vector<vector<int>> merge_subarray(vector<vector<int>> &arr){
//     int n = arr.size();
//     vector<vector<int>> ans;

//     sort(arr.begin(),arr.end());

//     for(int i=0; i<n; i++){
//         int start = arr[i][0], end = arr[i][1];
//         if(!ans.empty() && arr[i][0] <= ans.back()[1]){
//             continue;
//         }
//         for(int j=i+1; j<n; j++){
//             if(arr[j][0] <= end){
//                 end = max(end,arr[j][1]);
//             }
//             else{
//                 break;
//             }
//         }
//         ans.push_back({start,end});
//     }
//     return ans;
// }


vector<vector<int>> merge_subarray(vector<vector<int>> &arr){
    int n = arr.size();
    vector<vector<int>> ans;

    sort(arr.begin(),arr.end());

    int start = 0, end = 0;
    for(int i=0; i<n; i++){
        if(ans.empty() || arr[i][0] > ans.back()[1]){
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> arr = {{1,3},{2,6},{8,10},{15,18}};

    vector<vector<int>> ans = merge_subarray(arr);

    for(auto row : ans){
        for(int val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}