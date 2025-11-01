// Check if a given string is palindrome

#include<iostream>
using namespace std;


// // Iterative approach
// bool palindrome(string s){
//     int st = 0;
//     int end = s.length()-1;

//     while(end>st){
//         if(s[st] != s[end]){
//             return false;
//         }
//         st++, end --;
//     }
//     return true;
// }

// Recursive approach
bool palindrome(string s, int st, int end){
    if(st<end){
        if(s[st] != s[end]){
            return false;
        }
        palindrome(s,st+1, end-1);
    }
    return true;
}

int main(){
    string s = "abcdcba ";

    if(palindrome(s, 0, s.length() - 1)){
        cout << s << " is a palindrome"  << endl;
    }
    else{
        cout << s << " is not a palindrome" << endl;
    }

    return 0;
}