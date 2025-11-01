// Given an array, find the second smallest and second largest element in an arry
// Return -1 if both does not exists 

#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;


// // 1. Brute force approach (only valid for array with non duplicate elements)
// // TC : O(N* logN)

// void element(vector<int> &arr){
//     int n = arr.size();

//     if(n == 0 || n == 1) {
//          cout << -1 << " " << -1 << endl;
//          return;
//     }
//     sort(arr.begin(),arr.end());

//     int small = arr[1];
//     int large = arr[n-2];

//     cout << "Second smallest element : " << small << endl;
//     cout << "Second largest element : " << large << endl;    
// }

// // 2. Better approach
// // TC : O(N)
// void element(vector<int> arr){
//     int n = arr.size();

//     if(n == 0 || n == 1){
//         cout << -1 << " " << -1 << endl;
//         return;
//     }    
        

//     int smallest = INT32_MAX, second_smallest = INT32_MAX;
//     int largest = INT32_MIN, second_largest = INT32_MIN;
    
//     for(int i=0; i<n; i++){
//         smallest = min(smallest,arr[i]);
//         largest = max(largest,arr[i]);
//     }

//     for(int i =0; i<n; i++){
//         if(arr[i] < second_smallest && arr[i] != smallest){
//             second_smallest = arr[i];
//         }
//         if(arr[i] > second_largest && arr[i] != largest){
//             second_largest = arr[i];
//         }
//     }

//     cout << "Second smallest element : " << second_smallest << endl;
//     cout << "Second largest element : " << second_largest << endl;


// }

// 3. Optimal approach
void element(vector<int> arr){
    int n = arr.size();

    if(n == 0 || n == 1){
        cout << -1 << " " << -1 << endl;
        return;
    }

    int smallest = INT32_MAX, second_smallest = INT32_MAX;
    int largest = INT32_MIN, second_largest = INT32_MIN;

    for(int i = 0; i<n; i++){
        if(arr[i] < smallest){
            second_smallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] < second_smallest && arr[i] != smallest){
            second_smallest = arr[i];
        }

        if(arr[i] > largest){
            second_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] > second_largest && arr[i] != largest){
            second_largest = arr[i];
        }
    }

    if(second_smallest == INT_MAX){
        second_smallest = -1;
    }
    if(second_largest == INT_MIN){
        second_largest = -1;
    }

    cout << "Second smallest element: " << second_smallest << endl;
    cout << "Second largest element: " << second_largest << endl;

}


int main(){
    vector<int> arr = {1,2,4,7,7,5};

    element(arr);

    return 0;
}