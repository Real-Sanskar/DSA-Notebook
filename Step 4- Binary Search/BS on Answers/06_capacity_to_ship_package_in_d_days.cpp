// Find minimum ship capacity to ship all packages within D days
// Rules:

// Ship packages in given order (cannot reorder)
// Each day, load packages until capacity reached
// Must ship all within D days

#include<bits/stdc++.h>
using namespace std;



// Linear Search (TC : O (sum - max) * N)

// Logic: Try capacities from max(weights) to sum(weights), find minimum valid
// Algorithm:

// Minimum capacity: max(weights) (must carry heaviest package)
// Maximum capacity: sum(weights) (carry all in 1 day)
// For each capacity, check if possible within D days

long long calculateDays(vector<int> &arr, int i){
    long long days = 1, weight = 0;
    for(int val: arr){
        if(weight + val > i){
            days++;
            weight = val;
        }
        else{
            weight += val;
        }
    }
    return days;
}

// int weightCapacity(vector<int> &arr, int d){
//     int minVal = *max_element(arr.begin(),arr.end());
//     int maxVal = 0;
//     for(int val: arr){
//         maxVal += val;
//     }

//     for(int i=minVal; i<=maxVal; i++){
//         long long daysNeeded = calculateDays(arr,i);

//         if(daysNeeded <= d){
//             return i;
//         }
//     }
//     return -1;
// }






// Binary Search (TC : O(log(max-min) * N))

// Logic: Binary search on capacity value
// Key Observation:

// Larger capacity → fewer days needed
// If capacity X works, capacity X+1 also works
// Monotonic property → find minimum capacity

int weightCapacity(vector<int> &arr, int d){
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);

    while(low <= high){
        int mid = low + (high - low)/2;
        long long daysNeeded = calculateDays(arr, mid);

        if(daysNeeded <= d){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    vector<int> arr = {5,4,5,2,3,4,5,6};
    int d = 5;

    cout << weightCapacity(arr,d) << endl;

    return 0;
}