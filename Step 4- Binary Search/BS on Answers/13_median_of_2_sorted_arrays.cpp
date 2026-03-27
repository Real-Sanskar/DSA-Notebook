// given 2 sorted arrays, find median of 2 arrays combined

#include<bits/stdc++.h>
using namespace std;


// 1. Brute force approach   (TC : O(M+N)   SC: O(M+N))

// Merge arr1 and arr2 into single sorted array
// If total length odd: return middle element
// If total length even: return average of two middle elements


// double median(vector<int> &arr1, vector<int> &arr2){
//     int n1 = arr1.size();
//     int n2 = arr2.size();
//     int n = n1+n2;
//     vector<int> merged;
//     int i=0, j=0;
//     double median = -1;

//     while(i<n1 && j<n2){
//         if(arr1[i] <= arr2[j]){
//             merged.push_back(arr1[i++]);
//         }
//         else{
//             merged.push_back(arr2[j++]);
//         }
//     }

//     while(i<n1){
//         merged.push_back(arr1[i++]);
//     }

//     while(j<n2){
//         merged.push_back(arr2[j++]);
//     }

//     if(n%2 == 0){
//         median = (merged[n/2] + merged[n/2 - 1])/2.0;
//     }
//     else{
//         median = merged[n/2];
//     }

//     return median;
// }





// 2. Better approach   (TC : O(M+N)   SC: O(1))

// Logic: Find median position elements without creating merged array
// Algorithm:

// Calculate median position(s)
// Use two pointers to traverse both arrays
// Stop when reaching median position(s)


// double median(vector<int> &arr1, vector<int> &arr2){
//     int n1 = arr1.size();
//     int n2 = arr2.size();
//     int n = (n1 + n2);
//     int idx2 = n/2;
//     int idx1 = n/2 - 1;
//     int i = 0, j = 0;
//     int cnt = 0;
//     int idx1ele = INT_MIN, idx2ele = INT_MIN;

//     while(i<n1 && j<n2){
//         if(arr1[i] < arr2[j]){
//             if(cnt == idx1) idx1ele = arr1[i];
//             if(cnt == idx2) idx2ele = arr1[i];
//             i++;
//             cnt++;
//         }
//         else{
//             if(cnt == idx1) idx1ele = arr2[j];
//             if(cnt == idx2) idx2ele = arr2[j];
//             j++;
//             cnt++;
//         }
//     }
//     while(i<n1){
//         if(cnt == idx1) idx1ele = arr1[i];
//         if(cnt == idx2) idx2ele = arr1[i];
//         i++;
//         cnt++;
//     }

//     while(j<n2){
//         if(cnt == idx1) idx1ele = arr2[j];
//         if(cnt == idx2) idx2ele = arr2[j];
//         j++;
//         cnt++;
//     }

//     if(n%2 == 1){
//         return idx2ele;
//     }
//     else{
//         return (double)(idx1ele + idx2ele)/2.0;
//     }
// }





// 3. Optimal (Binary Search)  (TC : O(log(min(n1,n2)))  SC : O(1))

// Logic: Binary search on smaller array to find partition point
// Key Concept:

// Partition both arrays such that:

// Left half has (m+n+1)/2 elements
// All elements in left ≤ all elements in right


// Median is from elements around


double median(vector<int> &arr1, vector<int> &arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();

    if(n1 > n2) median(arr2,arr1);

    int low = 0, high = n1;
    int n = (n1 + n2);
    int left = (n1 + n2 + 1)/2;
    while(low <= high){
        int mid1 = (low + high)/2;
        int mid2 = left - mid1;

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if(mid1 < n1) r1 = arr1[mid1];
        if(mid2 < n2) r2 = arr2[mid2];
        if(mid1 - 1 >= 0) l1 = arr1[mid1-1];
        if(mid2 - 1 >= 0) l2 = arr2[mid2-1];

        if(l1 < r2 && l2 < r1){
            if(n%2 == 1){
                return max(l1,l2);
            }
            return ((double)(max(l1,l2) + min(r1,r2)))/2.0;
        }
        else if(l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0;
}

int main(){
    vector<int> arr1 = {2,4,6};
    vector<int> arr2 = {1,3,5};

    cout << median(arr1,arr2) << endl;

    return 0;
}