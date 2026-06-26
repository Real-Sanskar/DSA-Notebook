// Given 2 strings, check if they are anagrams of each other

#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;


// 1. Brute force (Sorting) (TC : O(N*logN)   SC : O(1))

// sort both strings
// if sorted versions are equal -> anagram

// bool check_anagram(string s, string t){
//     int n1 = s.size();
//     int n2 = t.size();
//     if(n1 != n2) return false;

//     sort(s.begin(),s.end());
//     sort(t.begin(),t.end());

//     for(int i=0; i<n1; i++){
//         if(s[i] != t[i]){
//             return false;
//         }
//     }
//     return true;
// }



// 2. Optimal (2 freq arrays) (TC : O(N)   SC : O(2N))

// store frequency count of each string
// if each character has same freq count in both arrays -> anagram
// otherwise -> not anagram

// bool check_anagram(string s, string t){
//     if(s.length() != t.length()) return false;

//     int freq1[26] = {0};
//     int freq2[26] = {0};

//     for(char c : s) freq1[c - 'a']++;
//     for(char c : t) freq2[c - 'a']++;

//     for(int i=0; i<s.size(); i++){
//         if(freq1[i] != freq2[i]){
//             return false;
//         }
//     }
//     return true;
// }


// 3. Optimal (1 freq array) (TC : O(N)   SC : O(N))

// use freq[26];
// add +1 for each character in s
// add -1 for each character in t

// if all zeroes till end -> anagram
// if any non-zero -> not anagram

bool check_anagram(string s, string t){
    if(s.size() != t.size()) return false;

    int freq[26] = {0};

    for(int i=0; i<s.size(); i++){
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }

    for(int i=0; i<26; i++){
        if(freq[i] != 0){
            return false;
        }
    }
    return true;
}

int main(){
    string s = "CAT";
    string t = "ACT";

    if(check_anagram(s,t)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    return 0;
}