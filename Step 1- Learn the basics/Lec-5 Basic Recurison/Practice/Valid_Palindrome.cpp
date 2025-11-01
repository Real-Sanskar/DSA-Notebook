// Given a string s, return true if it is a palindrome, else return false

#include<iostream>
using namespace std;

bool isPalindrome(string s){
    int st = 0; 

    int end = s.length() - 1;

    while(end>st){
        while(end>st && !isalnum(s[st])){
            st++;
        }
        while(end>st && !isalnum(s[end])){
            end--;
        }
        if(tolower(s[st]) != tolower(s[end])){
            return false;
        }
        st++,end--;
    }
    return true;
}

int main(){
    string s = "A man, a plan, a canal: Panama";

    if(isPalindrome(s)){
        cout << "Palindrome" << endl;
    }
    else{
        cout << "Not a palindrome" << endl;
    }
    

    return 0;
}