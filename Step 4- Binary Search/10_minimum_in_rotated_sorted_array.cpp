#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int find_min(vector<int> &arr){
    int n = arr.size();
    int low = 0, high = n-1;
    int ans = INT_MAX;

    while(low <= high){
        if(arr[low] < arr[high]){
            ans = min(ans,arr[low]);
            break;
        }

        int mid = low + (high-low)/2;
        ans = min(ans,arr[mid]);

        if(arr[low] <= arr[mid]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {4,5,6,7,0,1,2,3};
    

    cout << find_min(arr) << endl;

    return 0;
}