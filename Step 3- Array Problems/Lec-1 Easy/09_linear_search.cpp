// Given an array, and an element, return the index of that element in that array
// If element not found, return -1

#include<iostream>
#include<vector>
using namespace std;

int linear_search(vector<int> arr, int item){
    int n = arr.size();

    for(int i=0; i<n; i++){
        if(arr[i] == item){
            return i;
        }
    }
    return -1;

}

int main(){
    vector<int> arr = {1,2,3,4,5};
    int item = 10;

    cout << linear_search(arr,item) << endl;

    return 0;
}