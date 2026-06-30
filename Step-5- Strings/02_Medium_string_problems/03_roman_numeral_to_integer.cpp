// Given a roman numeral, convert it to an integer

// Roman numerals are represented by seven different symbols: I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000
// For example: 2 is written as II, 12 is written as XII, 27 is written as XXVII.
// Roman numerals are usually written largest to smallest from left to right. But in six special cases, subtraction is used instead of addition:
// I before V or X → 4 and 9,
// X before L or C → 40 and 90,
// C before D or M → 400 and 900

#include<iostream>
#include<unordered_map>
using namespace std;



// Optimal (Mapping)  (TC : O(N)    SC : O(1))

// Creating mapping of Roman symbol -> integer value
// Traverse the string from LEFT to RIGHT
// For each character:
// if current value < next value -> SUBTRACT current
// else -> ADD current


int roman_to_int(string str){
    int n = str.size();

    unordered_map<char,int> mp = {{'I',1},{'V',5},{'X',10},{'L',50},{'C', 100},{'D', 500},{'M', 1000}};
    int converted = 0;
    for(int i=0; i<n-1; i++){
        if(mp[str[i]] < mp[str[i+1]]){
            converted -= mp[str[i]];
        }
        else{
            converted += mp[str[i]];
        }
    }
    converted += mp[str[n-1]];

    return converted;
}

int main(){
    string str = "MCMXCIV";

    cout << roman_to_int(str) << endl;

    return 0;
}