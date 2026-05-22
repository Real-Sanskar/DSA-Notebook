// Given 2 strings s and t, determine if they are isomorphic

// **RULES:**
// 1. 2 string are said to be isomorphic if the characters in s can be replaced to get t.
// 2. All occurrence of the character must be replaced with another character while preserving order of characters
// 3. No 2 characters may map a single character, but a character may map itself

#include<iostream>
using namespace std;


// Two hash maps

// Maintain 2 hash maps: s->t and t->s
// For each character pair, check if existing mapping is consistent.
// If a new mapping conflicts, return false

bool check_isomorphic(string s, string t){ 
    int m1[256] = {0}, m2[256] = {0};

    int size_s = s.size();
    int size_t = t.size();

    if(size_s != size_t) return false;

    for(int i=0; i<size_s; i++){
        char c1 = s[i];
        char c2 = t[i];

        if(m1[c1] == 0 && m2[c2] == 0){
            m1[c1] = c2;
            m2[c2] = c1;
        }
        else{
            if(m1[c1] != c2 && m2[c2] != c1){
                return false;
            }
        }
    }   
    return true;
}

int main(){
    string s = "paper";
    string t = "title";

    if(check_isomorphic(s,t)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    
    return 0;
}

