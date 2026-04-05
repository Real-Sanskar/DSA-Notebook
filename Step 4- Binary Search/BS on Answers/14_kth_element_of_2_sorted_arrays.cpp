#include<bits/stdc++.h>
using namespace std;


// 1. Brute force (TC : O(M+N)  SC : O(M+N))

// int findElement(vector<int> &a, vector<int> &b, int k){
//     int m = a.size();
//     int n = b.size();
//     vector<int> merged;
//     int size = m + n;
//     int i = 0, j = 0;

//     while(i<=m && j<=n){
//         if(a[i] <= b[j]){
//             merged.push_back(a[i++]);
//         }
//         else{
//             merged.push_back(b[j++]);
//         }
//     }

//     while(i<=m){
//         merged.push_back(a[i++]);
//     }
//     while(j<=n){
//         merged.push_back(b[j++]);
//     }

//     for(int i=0; i<size; i++){
//         if(i+1 == k){
//             return merged[i];
//         }
//     }
//     return -1;
// }



// 2. Better approach (TC : O(M+N)  SC: O(1))


// int findElement(vector<int> &a, vector<int> &b, int k){
//     int m = a.size();
//     int n = b.size();
//     int cnt = 0;
//     int i=0, j=0;
//     int ans = -1;

//     while(i<=m && j<=n){
//         if(a[i] <= b[j]){
//             if(cnt+1 == k) return a[i];
//             cnt++;
//             i++;
//         }
//         else{
//             if(cnt+1 == k) return b[cnt-1];
//             cnt++;
//             j++;
//         }
//     }

//     while(i<=m){
//         if(cnt+1 == k) return a[i];
//         i++;
//         cnt++;
//     }
//     while(j<=n){
//         if(cnt+1 == k) return b[j];
//         j++;
//         cnt++;
//     }
//     return -1;
// }





// 3. Optimal (Binary Search) (TC : O(min(m,n))  SC: O(1))

// Logic: Binary search to find partition where K elements on left
// Key Concept:

// Partition arrays such that exactly K elements are on left side
// Kth element is max of left partition elements (or min of right if needed)

// Algorithm:

// Binary search on smaller array
// For partition mid1 in arr1, calculate mid2 = K - mid1 in arr2
// Check if valid partition
// Adjust based on comparison

int findElement(vector<int> &a, vector<int> &b, int k){
    int n1 = a.size();
    int n2 = b.size();

    if(n1 > n2) return findElement(b,a,k);

    int n = n1 + n2;
    int low = max(0,k-n2);
    int high = min(k,n1);
    int left = k;

    while(low<=high){
        int mid1 = (low + high)/2;
        int mid2 = left - mid1;

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if(mid1 < n1) r1 = a[mid1];
        if(mid2 < n2) r2 = b[mid2];
        if(mid1-1 >= 0) l1 = a[mid1-1];
        if(mid2-1 >= 0) l2 = b[mid2-1];

        if(l1 < r2 && l2 < r1) return max(l1,l2);
        else if(l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return -1;
}

int main(){
    vector<int> a = {2,3,6,7,9};
    vector<int> b = {1,4,8,10};
    int k = 5;

    cout << findElement(a,b,k) << endl;
}