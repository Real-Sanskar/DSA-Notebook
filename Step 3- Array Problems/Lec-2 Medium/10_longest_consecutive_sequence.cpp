// given an array, find the length of longest consecutive sequence

#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<climits>
using namespace std;


// 1. Brute force (TC : O(N*N*N)  SC : (1))

// LOGIC : for each element : search next consecutive linearly
// for each x, serach for x+1, x+2, ... in array
// use linear search for each lookup
// track longest sequence 



// int longestSequence(vector<int> &arr){
//     int n = arr.size();

//     int longest = 0;
//     for(int i=0; i<n; i++){
//         int x = arr[i];
//         int count = 1;
//         while(true){
//             bool found = false;
            
//             for(int j=0; j<n; j++){
//                 if(arr[j] == x + 1){
//                     x++;
//                     count++;
//                     found = true;
//                     break;
//                 }
//             }

//             if(!found){
//                 break;
//             }
//         }
//         longest = max(longest,count);
//     }
//     return longest;
// }



// 2. Better approach  (TC : O(N*log(N))   SC : O(1))
// LOGIC : sort array, travese and count consecutive element
// Skip duplicates


// int longestSequence(vector<int> &arr){
//     int n = arr.size();

//     sort(arr.begin(),arr.end());

//     int count = 0, longest = 1, lastSmallest = INT_MIN;
//     for(int i=0; i<n; i++){
//         if(arr[i] - 1 == lastSmallest){
//             lastSmallest = arr[i];
//             count++;
//         }
//         else if(arr[i] != lastSmallest){
//             lastSmallest = arr[i];
//             count = 1;
//         }

//         longest = max(longest,count);
//     }
//     return longest;
// }




// 3. Optmial solution (TC : O(N) + O(N+N)    SC : O(N) )

// LOGIC : store ele in set, only count sequece start (where num - 1 doen't exists)

// Store all elements in unordered_set
// if num - 1 doen't exits => start searching consecutive linearly
// Track longest

int longestSequence(vector<int> &arr){
    int n = arr.size();
    unordered_set<int> s;

    for(int i=0; i<n; i++){
        s.insert(arr[i]);
    }

    int longest = 1;
    for(int val : s){
        if(s.find(val - 1) == s.end()){
            int count = 1;
            int x = val;
            
            while(s.find(x+1) != s.end()){
                x++;
                count++;
            }
            longest = max(longest,count);
        }
    }
    return longest;
}


int main(){
    vector<int> arr = {100, 200, 1, 3, 2, 4};

    cout << longestSequence(arr) << endl;

    return 0;
}