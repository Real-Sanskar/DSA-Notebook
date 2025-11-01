#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// 1. Sorting the array and returning the last element
int largest_element(vector<int> &arr){
    sort(arr.begin(),arr.end());

    return *(arr.end()-1);
}


// // 2. Using a max variable
// int largest_element(vector<int> arr){
//     int largest = INT32_MIN;
//     for(auto val :arr){
//         if(val > largest){
//             largest = val;
//         }
//     }
//     return largest;
// }

int main(){
    vector<int> arr = {2,5,1,3,0};

    cout << largest_element(arr) << endl;

    return 0;
}