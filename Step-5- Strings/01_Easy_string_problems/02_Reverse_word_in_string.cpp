// Reverse the order of words in a string
// RULES: 
// 1. Words are sepeated by spaces
// 2. Remove leading/trailing spaces
// 3. Reduce multiple space to single space

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;




// 1. Brute force (Split and Reverse)   (TC : O(N)   SC : O(N))

// Split the string into words
// Reverse the words array
// Join them with single space


// string reverse_string(string str){
//     vector<string> words;
//     string ans = "";
//     string word = "";

//     for(int i=0; i<str.size(); i++){
//         if(str[i] != ' '){
//             word += str[i];
//         }
//         else if(!word.empty()){
//             words.push_back(word);
//             word = "";
//         }
//     }
//     if(!word.empty()){
//         words.push_back(word);
//     }

//     reverse(words.begin(),words.end());

//     for(int i=0; i<words.size(); i++){
//         ans += words[i];
//         if(i < words.size()-1){
//             ans += " ";
//         }
//     }
//     return ans;
// }






// 2. Two pointer (Backward Scan)   (TC : O(N)   SC : O(1))

// Start from end of string
// Skip trailing spaces
// Extract words from right to left
// Add to result with spaces


string reverse_string(string str){
    int n = str.length();
    string ans = "";

    int i=n-1;
    while(i>=0){
        while(i>=0 && str[i] == ' '){
            i--;
        }
        if(i < 0) break;
        
        int end = i;
        while(i>=0 && str[i] != ' '){
            i--;
        }
        int start = i+1;

        if(!ans.empty()){
            ans += ' ';
        }

        ans += str.substr(start, end - start + 1);
    }
    return ans;
}



int main(){
    string str = " welcome to jungle ";

    cout << reverse_string(str) << endl;
}