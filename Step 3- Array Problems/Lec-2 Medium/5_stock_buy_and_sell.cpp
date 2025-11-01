// Given an array of stock price on each day
// Obtain max profit buy buyin some day and selling other day
// If profit not possible then return 0;

#include<iostream>
#include<vector>
#include<climits>
using namespace std;


// 1. Brute force approach (using 2 loops)
// LOGIC : find all possible profit(sell - buy) and return maximum

// loop-1 : all possible buys
// loop-2: all possible sells
//        calcualte currProfit = sell - buy
//        return max profit

// TC : O(N*N)   SC : O(1)

// int profit(vector<int> &arr){
//     int n = arr.size();

//     int currProfit = 0, maxProfit = 0;
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             currProfit = arr[j] - arr[i];
//             maxProfit = max(maxProfit,currProfit);
//         }
//     }

//     return maxProfit;
// }


int profit(vector<int> &arr){
    int n = arr.size();

    int bestBuy = arr[0], maxProfit = 0;
    for(int i=1; i<n; i++){
        if(arr[i] > bestBuy){
            maxProfit = max(maxProfit, arr[i] - bestBuy);
        }
        if(arr[i] < bestBuy){
            bestBuy = arr[i];
        }
    }
    return maxProfit;
}

int main(){
    vector<int> arr = {7,6,4,3,1};


    cout << profit(arr) << endl;

    return 0;
}