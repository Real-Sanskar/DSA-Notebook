// Given an array containing only 0 and 1, return maximum consecutive ones in the array

#include<iostream>
#include<vector>
using namespace std;

int count_One(vector<int> &arr){
    int n = arr.size();
    int max_count = 0;
    int count = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == 1){
            count++;
        }
        else{
            count = 0;
        }
        max_count = max(max_count,count);
    }
    return max_count;
}

int main(){
    vector<int> arr ={1,1,0,1,1,1};

    cout << count_One(arr) << endl;

    return 0;
}