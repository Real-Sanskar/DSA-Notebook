// Given a string str, find the longest palindromic substring
// PALINDROMIC: Reads the string same in forward and backward direction

#include<iostream>
using namespace std;


// 1. Brute force (TC : O(N^3)   SC : O(1))

// Generate all substring
// Check if palindrome
// track longest

// bool isPalindrome(string str, int left, int right){
//     while(left < right){
//         if(str[left] != str[right]){
//             return false;
//         }
//         left++;
//         right--;
//     }
//     return true;
// }


// string longestPalindrome(string str){
//     int n = str.length();   
//     int maxLength = 0;
//     int startIdx = 0;

//     for(int i=0; i<n; i++){
//         for(int j=i; j<n; j++){
//             if(isPalindrome(str,i,j)){
//                 int length = j - i + 1;
//                 if(length > maxLength){
//                     maxLength = length;
//                     startIdx = i;
//                 }
//             }
//         }
//     }
//     return str.substr(startIdx, maxLength);
// }




// 2. Optimal (Expand around center)  (TC : O(N^2)   SC : O(1))

// Idea: Every palindrome has a center. Expand outward from each center while characters match. Two types of center:

// Odd length:  single char center → "aba"
// Even length: between two chars → "abba"

// ALGORITHM:
// for each index i:
//     1. expand around i (odd length center)
//     2. expand around i and i + 1 (even length center)
//     3. track longest palindrome found

int expand(string str, int left, int right){
    int n = str.size();

    while(str[left] == str[right]){
        left--;
        right++;

        if(left == -1 || right == n){
            break;
        }
    }
    // When loop ends:
    // s[left] != s[right] or out of bounds
    // Valid palindrome was s[left+1 .. right-1]
    // Length = (right-1) - (left+1) + 1 = right - left - 1
    return (right - left - 1);
}

string longestPalindrome(string str){
    int n = str.size();
    if(n <= 1) return str;

    int startIdx = 0;
    int maxLength = 1; // single character is always palindrome

    for(int i=0; i<n; i++){
        int oddLen = expand(str, i, i);

        int evenLen = expand(str, i, i+1);

        int currLen = max(oddLen, evenLen);

        if(currLen > maxLength){
            maxLength = currLen;
            // Calculate start index
            // Center i, length curLen
            // Start = i - (curLen-1)/2
            startIdx = i - (maxLength - 1)/2;
        }
    }
    return str.substr(startIdx, maxLength);
}

int main(){
    string str = "cbba";
    
    cout << longestPalindrome(str) << endl;

    return 0;
}