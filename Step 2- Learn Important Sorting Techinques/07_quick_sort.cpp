// Better than merge sort as no extra array is created

#include<iostream>
using namespace std;

void printArray(int arr[], int n){
    for(int i = 0 ; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i<j){
        while(arr[i] <= pivot && i < high){
            i++;
        }
        while(arr[j] > pivot && j > low){
            j--;
        }

        if(i < j) swap(arr[i],arr[j]);
    }

    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pIndex = partition(arr,low,high);

        quickSort(arr,low, pIndex-1);
        quickSort(arr,pIndex+1,high);

    }
}

int main(){
    int arr[] = {4,6,9,1,5,2};
    int n = 6;
    int low = 0;
    int high = n - 1;

    printArray(arr,n);
    quickSort(arr,low,high);
    printArray(arr,n);

    return 0;
}