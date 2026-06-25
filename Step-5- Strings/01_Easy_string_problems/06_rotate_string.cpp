// Given two strings s and goal, return true if s can become goal after some number of rotations.

#include<iostream>
#include<vector>
#include<string>
using namespace std;



// 1. Brute force (TC: O(N*N)  SC : O(N))

// Try all n rotation of s 
// Compare with goal for each


// bool isRotated(string s, string goal){
//     int n = s.size();

//     int i = 0;
//     for(int i=0; i<n; i++){
//         string rotated = s.substr(i) + s.substr(0,i);
//         if(rotated == goal){
//             return true;
//         }
//     }
//     return false;
// }




// 2. Optimal (TC : O(N)  SC : O(N))

// concatenate s with itself -> s + s
// check if goal is a substring of s + s


bool isRotated(string s, string goal){
    if(s.length() != goal.length()) return false;

    string doubled_S = s + s;

    int left = 0, right = s.length()-1;
    while(right < doubled_S.length()){
        if(doubled_S.substr(left,s.length()) == goal){
            return true;
        }
        left++, right++;
    }
    return false;
}

int main(){
    string s = "rotation";
    string goal = "tionrota";

    if(isRotated(s,goal)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    return 0;
}