// Problem Statement: A monkey Koko is given ‘n’ piles of bananas, whereas the 'ith' pile has ‘a[i]’ bananas. An integer ‘h’ is also given, which denotes the time (in hours) for all the bananas to be eaten.

// Each hour, the monkey chooses a non-empty pile of bananas and eats ‘k’ bananas. If the pile contains less than ‘k’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.

// Find the minimum number of bananas ‘k’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



// Linear Search

long long calculateTotalHours(vector<int> &arr, int speed){
    long long totalHours = 0;
    for(auto val: arr){
        totalHours += (val + speed - 1)/speed;
    }
    return totalHours;
}

// int minEatingSpeed(vector<int> &arr, int h){
//     int maxVal = *max_element(arr.begin(), arr.end());
//     for(int i=1; i<=maxVal; i++){
//         long long totalHours = calculateTotalHours(arr,i);

//         if(totalHours <= h){
//             return i;
//         }
//     }
//     return maxVal;
// }





int minEatingSpeed(vector<int> &arr, int h){
    int low = 1, high = *max_element(arr.begin(),arr.end());

    while(low <= high){
        int mid = low + (high-low)/2;
        long long totalHours = calculateTotalHours(arr,mid);

        if(totalHours <= h){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    vector<int> arr = {7,15,6,3};
    int h = 8;

    cout << minEatingSpeed(arr,h) << endl;

    return 0;
}