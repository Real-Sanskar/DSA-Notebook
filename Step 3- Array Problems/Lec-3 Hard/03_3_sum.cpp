// given an array of integers, fint unique triplets that adds up to 0

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;




// 1. Brute force approach (TC : O(N*N*N)   SC : O(N) for set)

// LOGIC : Try all possible triplet using 3 nested loops
// ALGORITHM : 
// For each (i,j,k) , check if (arr[i] + arr[j] + arr[k] == 0)
// store triplet in set<vector<int>> to avoid duplicates

// set<vector<int>> three_sum(vector<int> &arr){
//     int n = arr.size();

//     set<vector<int>> ans;

//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             for(int k=j+1; k<n; k++){
//                 int sum = arr[i] + arr[j] + arr[k];
//                 if(sum == 0){
//                     vector<int> temp = {arr[i],arr[j],arr[k]};
//                     sort(temp.begin(),temp.end());
//                     ans.insert(temp);
//                 }
//             }
//         }
//     }
//     return ans;
// }





// 2. Better approach (Hash set) (TC : O(N*N)     SC : O(N*N))

// LOGIC : fix 2 elements, find third using hash set
// ALGORITHM : 
// fix i, then fix j
// find -(arr[i] + arr[j]) in Hash set
// collect triplets

// set<vector<int>> three_sum(vector<int> &arr){
//     int n = arr.size();
//     set<vector<int>> ans;

//     for(int i=0; i<n; i++){
//         set<int> temp;
//         for(int j=i+1; j<n; j++){
//             int tar = 0 - arr[i] - arr[j];
//             if(temp.find(tar) != temp.end()){
//                 vector<int> sol = {arr[i],arr[j],tar};
//                 sort(sol.begin(),sol.end());
//                 ans.insert(sol);
//             }
//             temp.insert(arr[j]);
//         }
//     }
//     return ans;
// }



// 3. Optmial approach (sorting + 2 pointer) (TC : O(N*N)    SC : O(1))

// LOGIC : sort array, fix 1 element and use two pointers to find pairs
// ALGORITHM : 
// sort array
// fix i, move j = i+1, k = n-1
// if sum == 0 , store triplet, skip duplicates, move both pointers
// if sum < 0, move left
// if sum > 0 , move right 
// skip duplicate i values  

vector<vector<int>> three_sum(vector<int> &arr){
    int n = arr.size();

    sort(arr.begin(),arr.end());

    vector<vector<int>> ans;

    for(int i=0; i<n-2; i++){
        int j = i+1, k = n-1;
        if(i!=0 && arr[i] == arr[i-1]) continue;
        while(j < k){
            int sum = arr[i] + arr[j] + arr[k];
            if(sum > 0){
                k--;
            }
            else if(sum < 0){
                j++;
            }
            else{
                ans.push_back({arr[i],arr[j],arr[k]});
                j++;
                k--;

                while(j < k && arr[j] == arr[j-1]) j++;
                while(j < k && arr[k] == arr[k+1]) k--;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {-1,0,1,2,-1,-4};

    // set<vector<int>> ans = three_sum(arr);

    vector<vector<int>> ans = three_sum(arr);

    for(auto row : ans){
        for(int val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}