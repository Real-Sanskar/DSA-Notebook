#include<bits/stdc++.h>
using namespace std;


int countStudent(vector<int> &arr, int maxPages, int m){
    int stu = 1;
    long long pageCount = 0;

    for(int i=0; i<arr.size(); i++){
        if(pageCount + arr[i] <= maxPages){
            pageCount += arr[i];
        }
        else{
            stu++;
            pageCount = arr[i];
        }
    }
    return stu;
}

int pageAllocation(vector<int> &arr, int m){
    int minVal = *max_element(arr.begin(),arr.end());
    int maxVal = accumulate(arr.begin(),arr.end(),0);

    int ans = -1;
    if(m > arr.size()) return ans;

    for(int i=minVal; i<=maxVal; i++){
        if(countStudent(arr,i,m) == m){
            return i;
        }
    }
    return -1;
}


// int pageAllocation(vector<int> &arr, int m){
//     int low = *max_element(arr.begin(),arr.end());
//     int high = accumulate(arr.begin(),arr.end(),0);

//     int ans = -1;
//     if(m > arr.size()) return ans;

//     while(low <= high){
//         int mid = low + (high - low)/2;
//         if(countStudent(arr,mid,m) <= m){
//             high = mid - 1;
//             ans = mid;
//         }
//         else{
//             low = mid + 1;
//         }
//     }
//     return ans;
// }

int main(){
    vector<int> arr = {12,34,67,90};
    int m = 2;

    cout << pageAllocation(arr,m) << endl;

    return 0;
}