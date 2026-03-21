// Given an array of n gas station positions(sorted), and integer k(new stations to add)
// place k new gas stations to minmize maximum distance b/w gas stations

#include<bits/stdc++.h>
using namespace std;



// 1. Brute force  (TC : O(K * N) + O(N),  SC : O(N))

// Track stations added per section, repeatedly find and update max

// long double maxDistance(vector<int> &arr, int k){
//     int n = arr.size();
//     vector<int> howMany(n-1,0);

//     for(int i=1; i<=k; i++){
//         long double maxVal = -1;
//         int maxIdx = -1;

//         for(int j=0; j<n-1; j++){
//             long double dist = arr[j+1] - arr[j];
//             long double sectionLength = dist/ (howMany[j] + 1);

//             if(sectionLength > maxVal){
//                 maxVal = sectionLength;
//                 maxIdx = j;
//             }
//         }
//         howMany[maxIdx]++;
//     }

//     long double maxDistance = -1;
//     for(int i=0; i<n-1; i++){
//         long double dist = arr[i+1] - arr[i];
//         long double sectionLength = dist/(howMany[i] + 1);

//         maxDistance = max(maxDistance,sectionLength);
//     }
//     return maxDistance;
// }






// 2. Better approach (Priority Queue)  (TC : O(K*logN) + O(N*logN),  SC : O(N))

// find current maxDist using priority queue, then add new station and update the maxDistance onto queue


// long double maxDistance(vector<int> &arr, int k){
//     int n = arr.size();
//     priority_queue<pair<long double,int>> pq;
//     vector<int> howMany(n-1,0);

//     for(int i=0; i<n-1; i++){
//         pq.push({(long double)(arr[i+1]-arr[i]),i});
//     }

//     for(int i=1; i<=k; i++){
//         auto top = pq.top();
//         pq.pop();
//         int maxIdx = top.second;
//         howMany[maxIdx]++;
        
//         long double dist = arr[maxIdx+1] - arr[maxIdx];
//         long double sectionLength = dist/(howMany[maxIdx] + 1);
//         pq.push({sectionLength,maxIdx});
//     }
//     return pq.top().first;
// }






// 3. Optimal approach (BS on answer)  (TC :  O(N*log(maxLen)) + O(N),   SC : O(1))

// Key Observation:

// If maxDist=X possible with K stations → X+0.01 also possible
// Monotonic property
// Find minimum maxDist

// Algorithm:

// Binary search: low=0, high=max(gap)
// Precision: 1e-6 (or use iteration count)
// For each mid (maxDist):

// Count stations needed to achieve this maxDist
// If needed ≤ K: ans=mid, try smaller (high=mid)
// Else: try larger (low=mid)



// Helper: Count stations needed for given maxDist

// For each gap: need ⌊gap / maxDist⌋ stations


int gasStationsRequired(vector<int> &arr, long double dist){
    int cnt = 0;
    int n = arr.size();
    for(int i=1; i<n; i++){
        int gasStationsInBetween = (arr[i]-arr[i-1])/dist;
        if((arr[i] - arr[i-1]) == gasStationsInBetween * dist){
            gasStationsInBetween--;
        }
        cnt += gasStationsInBetween;
    }
    return cnt;
}


long double maxDistance(vector<int> &arr, int k){
    int n = arr.size();
    long double low = 0;
    long double high = 0;
    long double ans = -1;
    for(int i=1; i<n; i++){
        high = max(high,(long double)(arr[i]-arr[i-1]));
    }

    long double dist = 1e-6;
    while((high - low) > 1e-6){
        long double mid = (low + high)/(2.0);

        int cnt = gasStationsRequired(arr,mid);
        if(cnt > k){
            low = mid;
        }
        else{
            high = mid;
            ans = mid;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    int k = 4;

    cout << maxDistance(arr, k) << endl;
}