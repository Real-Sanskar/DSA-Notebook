// Give 2 arrays of size m and n, find the union of the 2 sorted arrays

// Union : Common and distinct elements in 2 arrays

// Example : arr1= {1,2,3,4,5} m = 5
//           arr2= {2,2,3,4,5} n = 5
//           Union = {1,2,3,4,5} 
// common elements : 2,3,4,5
// Distinct elements : 1

#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;

// Solution-1: Using map and a result vector
// TC : O((m+n)*log(m+n))    SC : O(m+n)

// void Union(vector<int> arr1, vector<int> arr2, int m, int n){
//     map<int,int> freq;
//     vector<int> result;

//     for(int i=0; i<m; i++){
//         freq[arr1[i]]++;
//     }
//     for(int i=0; i<n; i++){
//         freq[arr2[i]]++;
//     }
//     for(auto val : freq){
//         result.push_back(val.first);
//     }
//     cout << "Union of both array are : ";
//     for(auto val : result){
//         cout << val << " ";
//     }
//     cout << endl;
// }


// Solution-2: Using a set
// TC : O(m+n)   SC : O(m+n)

// void Union(vector<int> arr1, vector<int> arr2, int m, int n){
//     set<int> result;

//     for(int i=0; i<m; i++){
//         result.insert(arr1[i]);
//     }
//     for(int i=0; i<n; i++){
//         result.insert(arr2[i]);
//     }

//     cout << "Union of 2 arrays are : ";
//     for(auto val : result){
//         cout << val << " ";
//     }
//     cout << endl;
// }


// Solution-3: Using 2 pointer
// TC : O(m+n)   SC : O(m+n)

void Union(vector<int> arr1, vector<int> arr2, int m, int n){
    vector<int> temp;

    int i=0,j=0;
    while(i<m && j<n){
        if(!temp.empty() && temp.back() == arr1[i]){
            i++;
            continue;
        }
        if(!temp.empty() && temp.back() == arr2[j]){
            j++;
            continue;
        }
        if(arr1[i] < arr2[j]){
            temp.push_back(arr1[i]);
            i++;
        }
        else if(arr1[i] > arr2[j]){
            temp.push_back(arr2[j]);
            j++;
        }
        else{
            temp.push_back(arr1[i]);
            i++; j++;
        }
    }
    while(i<m){
        if(!temp.empty() && temp.back() != arr1[i]){
            temp.push_back(arr1[i]);
        }
        i++;
    }
    while(j<n){
        if(!temp.empty() && temp.back() != arr2[j]){
            temp.push_back(arr2[j]);
        }
        j++;
    }

    cout << "Array after union of 2 arrays is : ";
    for(auto val : temp){
        cout << val << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr1 = {1,2,3,4,5};
    int m = arr1.size();
    vector<int> arr2 = {2,2,3,4,5};
    int n = arr2.size();

    Union(arr1,arr2,m,n);

    return 0;
}