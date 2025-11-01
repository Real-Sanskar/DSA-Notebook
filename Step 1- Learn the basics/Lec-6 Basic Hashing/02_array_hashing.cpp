// Character hashing
// 'a' = 97
// corresponding value = character - 'a'
// Ex- 'f' - 'a' = 5 -> so f count will be at index 5

#include<iostream>
using namespace std;


// // 1. Only (capital/small) elements present in string
// int main(){
//     string s = "abcdcba";

//     int hash[26] = {0};
//     for(int i=0; i<s.size(); i++){
//         hash[s[i]-'a'] += 1; 
//     }

//     int q;
//     cin >> q;
//     while(q--){
//         char c;
//         cin >> c;

//         cout << hash[c-'a'] << endl;
//     }

//     return 0;
// }

// 2. When both capital and small elements are present
// hash array size = 256
int main(){
    string s;
    cin >> s;

    int hash[256] = {0};
    for(int i=0; i<s.size(); i++){
        hash[s[i]] += 1;
    }

    int q;
    cin >> q;
    while(q--){
        char c;
        cin >> c;

        cout << hash[c] << endl;
    }

    return 0;
}