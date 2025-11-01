// Hashing -> combination of pre-storing and fetching

// Given an array and a list of query , return the number of occurence of each query in the array

// This is integer array hashing
// array hashing -> cant store large number of elements, so map hashing is used

#include<iostream>
using namespace std; 

int main(){
    int n;
    cin >> n; // Input number of elements

    int arr[n]; // array of size n
    for(int i=0; i<n; i++){
        cin>> arr[i]; // Input each element
    }

    //precompute
    int hash[13] = {0}; // Considering max element to be 13, initialize each element with 0;
    // these index will work as the element and will store count
    for(int i=0; i<n; i++){
        hash[arr[i]] += 1;
    }

    int q; // Input number of queries
    cin >> q;
    while(q--){
        int number; // Input each query
        cin >> number;
        cout << hash[number] << endl; // Printing count of each query
    }

    return 0;
}