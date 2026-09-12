#include<iostream>
#include<vector>
using namespace std;


// =========================================================
// Function to generate binary strings using backtracking
// =========================================================
//
// Idea:
// At every position, we have two choices:
//
// 1. Put '0' -> always allowed
// 2. Put '1' -> allowed only if previous character was '0'
//
// This prevents consecutive 1s.
//
// `current` stores the string currently being built.
// `ans` stores all valid binary strings.
//
// TC: O(2^N)
// SC: O(N) recursion stack
// =========================================================

void generate(int index, int prev, int n, string& current, vector<string>& ans){

    // base case:
    // string has reached length n
    if(index == n){

        // store the valid string
        ans.push_back(current);

        return;
    }


    // -----------------------------------------------------
    // Choice 1: Put '0'
    // -----------------------------------------------------
    //
    // 0 can always be placed,
    // regardless of the previous character.
    current.push_back('0');


    // move to the next position
    // prev becomes 0 because we just placed '0'
    generate(index + 1, 0, n, current, ans);


    // backtrack:
    // remove the last character
    // so we can try another choice
    current.pop_back();


    // -----------------------------------------------------
    // Choice 2: Put '1'
    // -----------------------------------------------------
    //
    // We can place '1' only when the previous character
    // was not '1'.
    //
    // prev == 0 means placing '1' will not create "11".
    if(prev == 0){

        // choose '1'
        current.push_back('1');


        // move to the next position
        // prev becomes 1 because we just placed '1'
        generate(index + 1, 1, n, current, ans);


        // backtrack:
        // remove the last character
        current.pop_back();
    }
}


// =========================================================
// Function to generate all valid binary strings
// =========================================================

vector<string> generateBinaryStrings(int n){

    // create an empty vector to store answers
    //
    // IMPORTANT:
    // Do NOT use vector<string> ans(n)
    // because that creates n empty strings.
    vector<string> ans;


    // stores the binary string currently being built
    string current;


    // start generating from index 0
    //
    // prev = 0 means initially there is no previous '1',
    // so both '0' and '1' are allowed.
    generate(0, 0, n, current, ans);


    // return all valid binary strings
    return ans;
}


int main(){

    // length of each binary string
    int n = 3;


    // generate all binary strings of length n
    // without consecutive 1s
    vector<string> ans = generateBinaryStrings(n);


    // print all generated strings
    for(string val: ans){
        cout << val << " ";
    }


    return 0;
}