// Given a string str and integer k
// Return number of substrings with exactly k distinct characters

#include<iostream>
#include<unordered_set>
using namespace std;



// 1. Brute force : (TC : O(N^3)   SC : O(N))

// Generate all substrings 
// count distinct characters in each 
// if exactly k -> increament count


// int countSubstrings(string str, int k){
//     int n = str.size();

//     int count = 0;
//     for(int i=0; i<n; i++){
//         for(int j=i; j<n; j++){
//             unordered_set<char> distinct;

//             for(int l=i; l<=j; l++){
//                 distinct.insert(str[l]);
//             }
//             if(distinct.size() == k){
//                 count++;
//             }   
//         }
//     }
//     return count;
// }




// 2. Optimized Brute force (TC : O(N^2)  SC : O(1))

// Instead of recounting distinct chars from scratch
// MAINTAIN the set as we extend the substring


// int countSubstrings(string str, int k){
//     int n = str.size();
//     int count = 0;

//     for(int i=0; i<n; i++){
//         int freq[26] = {0};
//         int distinct = 0;

//         for(int j=i; j<n; j++){
//             if(freq[str[j] - 'a'] == 0){
//                 distinct++;
//             }
//             freq[str[j] - 'a']++;

//             if(distinct == k){
//                 count++;
//             }

//             if(distinct > k){
//                 break;
//             }
//         }
//     }
//     return count;
// }



// Optimal (Sliding Window) (TC : O(N)   SC : O(1))

// KEY FORMULA
// exactly(k) = atMost(k) - atMost(k-1)
// WHY?
//   atMost(k) includes substrings with 0,1,2,...,k distinct
//   atMost(k-1) includes substrings with 0,1,2,...,k-1 distinct
//   Subtract → only substrings with EXACTLY k distinct remain!


// WHY NOT DIRECT SLIDING WINDOW?
// Sliding window works for:
//   ✓ "at most k" → easy to shrink when > k
//   ✓ "at least k" → can be converted

// Does NOT directly work for:
//   ✗ "exactly k" → hard to maintain exact count

// For "at most k distinct":
//   INVALID means: distinct > k
//   When we see distinct > k, we SHRINK
//   When distinct <= k, we COUNT


// ||**ALGORITHM**||

// Maintain window [left...right]:
//     freq[26] array
//     distinct count

// EXPAND right:
//     ADD s[right]
//     if new char -> distinct++

// SHRINK left (while distinct > k)  
//     REMOVE s[left]
//     if freq becomes 0 -> distinct--
//     left++;

// COUNT:
//   count += (right - left + 1)
//   ← All substrings ending at right, starting from left..right
//   ← All have ≤ k distinct (because full window has ≤ k)


int atMost(string str, int k){
    if(k <= 0) return 0;

    int n = str.size();

    int left = 0;
    int distinct = 0;
    int count = 0;
    int freq[26] = {0};

    for(int right=0; right<n; right++){
        if(freq[str[right] - 'a'] == 0){
            distinct++;
        }
        freq[str[right] - 'a']++;

        while(distinct > k){
            freq[str[left] - 'a']--;

            if(freq[str[left] - 'a'] == 0){
                distinct--;
            }
            left++;
        }

        count += right - left + 1;
    }
    return count;
}

int countSubstrings(string str, int k){
    return atMost(str,k) - atMost(str,k-1);
}


int main(){
    string str = "aabaa";
    int k = 1;

    cout << countSubstrings(str,k) << endl;

    return 0;
}