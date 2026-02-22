// Problem: Find minimum days to make M bouquets, each needing K adjacent bloomed roses

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;




// Linear Search (TC : O((max(arr)-min(arr)) * n))

// Logic: Try each day from min to max, check if M bouquets possible
// Algorithm:
// For day from min(arr) to max(arr):

// Count bouquets possible on that day
// If count ≥ M: return day

// Helper Function: Count bouquets on given day

int calculateBouquets(vector<int> &arr, int i, int k){
    int roses = 0, bouquets = 0;
    for(int val: arr){
        if(val <= i){
            roses++;
            if(roses == k){
                bouquets++;
                roses = 0;
            }
        }
        else{
            roses = 0;
        }
    }
    return bouquets;
}

// int minDays(vector<int> &arr, int m, int k){
//     long long n = arr.size();
//     long long totalFlowers = 1LL * m * k;
//     if(totalFlowers > n) return -1;

//     int minVal = *min_element(arr.begin(), arr.end());  
//     int maxVal = *max_element(arr.begin(),arr.end());
//     for(int i=1; i<= maxVal; i++){
//         int maxBouquets = calculateBouquets(arr,i,k);

//         if(maxBouquets >= m){
//             return i;
//         }
//     }
//     return -1;
// }





// Binary Search (TC : O( log{max(arr)-min(arr)} * N)

// Logic: Binary search on answer space (days)
// Key Observation:

// If we can make M bouquets on day X
// We can also make M bouquets on day X+1, X+2... (more roses bloom)
// Monotonic property → Binary search applicable

int minDays(vector<int> &arr, int m, int k){
    long long n = arr.size();
    long long totalFlowers = 1LL * m * k;
    if(totalFlowers > n) return -1;

    int low = *min_element(arr.begin(),arr.end()), high = *max_element(arr.begin(),arr.end());
    int ans = 0;

    while(low <= high){
        int mid = low + (high-low)/2;
        int totalBouquets = calculateBouquets(arr,mid,k);

        if(totalBouquets >= m){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12 , 7};
    int m = 2, k = 3;

    cout << minDays(arr,m,k) << endl;

    return 0;
}