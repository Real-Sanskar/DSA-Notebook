#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int> arr){
    for(auto val : arr){
        cout << val << " ";
    }
    cout << endl;
}

void merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;

    while(left<= mid && right <= high){
        if(arr[left] < arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low; i<= high; i++){
        arr[i] = temp[i-low];
    }

}

void mergeSort(vector<int> &arr, int low, int high){
    if(low < high){
        int mid = low + (high-low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr,mid+1, high);
    
        merge(arr, low, mid, high);
    }
}

int main(){
    vector<int> arr = {4,6,9,1,5,2};
    int n = arr.size();
    int low = 0;
    int high = n - 1;

    printArray(arr);
    mergeSort(arr,low,high);
    printArray(arr);

    return 0;
}