// Hashing using map

// unordered map is used as its TC=O(1)

// Consider interger hashing
#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    // pre-storing
    unordered_map<int,int> m;
    for(int i=0; i<n; i++){
        m[arr[i]]++;
    }
    
    // iterating over map
    // for(auto val:m){
    //     cout << val.first << " " << val.second << endl;
    // }

    int q;
    cin >> q;

    while(q--){
        int number;
        cin >> number;
        // fetching
        cout << m[number] << endl;
    }

    return 0;
}