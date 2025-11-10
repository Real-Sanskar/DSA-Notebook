// given an array, find elements that appears more than n/3 times
// if no such element exists, return empty vector

#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;

// vector<int> majority_element(vector<int> &arr){
//     int n = arr.size();

//     vector<int> ans;
//     for(int i=0; i<n; i++){
//         int count = 0;
//         if(ans.size() == 0 || ans[0] != arr[i]){
//             for(int j=0; j<n; j++){
//                 if(arr[i] == arr[j]){
//                 count++;
//                 }
//             }
//         }
        
//         if(count > n/3){
//             ans.push_back(arr[i]);
//         }

//         if(ans.size() == 2){
//             break;
//         }
//     }
//     return ans;
// }



// vector<int> majority_element(vector<int> &arr){
//     int n = arr.size();

//     vector<int> ans;

//     unordered_map<int,int> freq;
//     int count = 0;
//     for(int i=0; i<n; i++){
//         freq[arr[i]]++;
//     }

//     for(auto val : freq){
//         if(val.second > n/3){
//             ans.push_back(val.first);
//         }
//     }

//     return ans;
// }



vector<int> majority_element(vector<int> &arr){
    int n = arr.size();

    vector<int> ans;
    int count1 = 0, count2 = 0;
    int ele1 = INT_MIN, ele2 = INT_MIN;

    for(int i=0; i<n; i++){
        if(count1 == 0 && arr[i] != ele2){
            ele1 = arr[i];
            count1++;
        }
        else if(count2 == 0 && arr[i] != ele1){
            ele2 = arr[i];
            count2++;
        }
        else if(arr[i] == ele1){
            count1++;
        }
        else if(arr[i] == ele2){
            count2++;
        }
        else{
            count1--, count2--;
        }
    }

    count1 = 0 , count2 = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == ele1){
            count1++;
        }
        if(arr[i] == ele2){
            count2++;
        }
    }

    if(count1 > n/3){
        ans.push_back(ele1);
    }
    if(count2 > n/3){
        ans.push_back(ele2);
    }

    return ans;
}



int main(){
    vector<int> arr = {2,2,1,3};

    vector<int> ans = majority_element(arr);

    for(int val : ans){
        cout << val << " ";
    }

    return 0;
}