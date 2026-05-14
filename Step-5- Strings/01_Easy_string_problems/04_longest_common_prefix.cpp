// Find longest common prefix string amongst an array of strings.
// If there is no common prefix, return ""

#include<iostream>
#include<string>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;




// 1. Vertical Scanning (Character by character)   (TC : O(N*M))

// At each position i:
//   Compare character at position i across ALL strings
//   If all same → add to prefix
//   If any differs → STOP, return prefix so far

// Also stop if any string ends at position i!



// string longest_common_prefix(vector<string> str){
//     int n = str.size();
//     string prefix = "";
//     int minLen = INT_MAX;
//     for(string& s:str){
//         minLen = min(minLen, (int)s.length());
//     }

//     for(int i=0; i<minLen; i++){
//         char current = str[0][i];
//         for(int j=1; j<n; j++){
//             if(current != str[j][i]){
//                 return prefix;
//             }
//         }
//         prefix += current;
//     }
//     return prefix;
// }





// 2. Vertical scan (Compare with first string)   (TC : O(N*M))

// Take first string as initial prefix
// For each next string:
//   Shrink prefix until it matches current string
//   If prefix becomes "" → return ""

// LCP of all = LCP computed incrementally


// string commonPrefix(string prefix, string str){
//     int i=0;
//     while(i<prefix.length() && i<str.length() && prefix[i] == str[i]){
//         i++;
//     }
//     return str.substr(0,i);
// }

// string longest_common_prefix(vector<string> str){
//     int n = str.size();
//     if(str.empty()) return "";

//     string prefix = str[0];

//     for(int i=1; i<n; i++){
//         prefix = commonPrefix(prefix, str[i]);
//     }
//     return prefix;
// }




// 3. sort + compare extremes   (TC : O(N*logM + M))

// Sort the array lexicographically
// Compare ONLY first and last string

// Why it works:
//   In sorted order, first and last are most different
//   If they share a prefix, ALL strings share it


string longest_common_prefix(vector<string> str){
    int n = str.size();
    string prefix = "";

    sort(str.begin(),str.end());

    string first = str[0];
    string last = str[n-1];
    int i=0;
    while(i<first.length() && i<last.length() && first[i] == last[i]){
        prefix += first[i];
        i++;
    }
    return prefix;
}

int main(){
    vector<string> str = {"flower","flow","flight"}; 

    cout << longest_common_prefix(str) << endl;
}