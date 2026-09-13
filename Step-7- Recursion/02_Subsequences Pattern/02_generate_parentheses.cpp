#include<iostream>
#include<vector>
using namespace std;


// =========================================================
// 1. Brute Force Approach
// =========================================================
//
// Idea:
// Generate every possible string of length 2*n using '('
// and ')'.
//
// After generating a string, check whether it is valid.
//
// For a valid parentheses string:
// 1. Number of '(' must be equal to number of ')'
// 2. At no point can ')' exceed '('
//
// TC: O(2^(2N) * N)
// SC: O(N) recursion stack
//      + O(N) for current string
//      + output space
// =========================================================


// ---------------------------------------------------------
// Function to check whether a parentheses string is valid
// ---------------------------------------------------------

// bool isValid(string current){

//     // balance keeps track of unmatched '('
//
//     // '(' -> balance++
//     // ')' -> balance--
//     int balance = 0;


//     // check every character
//     for(char ch: current){

//         // opening bracket increases balance
//         if(ch == '(') balance++;

//         // closing bracket decreases balance
//         else balance--;


//         // if balance becomes negative,
//         // there are more ')' than '('
//         // so the string is invalid
//         if(balance < 0){
//             return false;
//         }
//     }


//     // for a valid string, all '(' must be closed
//     // therefore balance must finally become 0
//     return (balance == 0);
// }


// ---------------------------------------------------------
// Generate all possible parentheses strings
// ---------------------------------------------------------

// void generateAll(string& current, vector<string>& ans, int n){

//     // a valid parentheses string contains exactly 2*n
//     // characters
//     if(current.length() == 2*n){

//         // store only valid strings
//         if(isValid(current)) ans.push_back(current);

//         return;
//     }


//     // choose '('
//     current.push_back('(');

//     // explore this choice
//     generateAll(current, ans, n);

//     // backtrack:
//     // remove '(' and try the next choice
//     current.pop_back();


//     // choose ')'
//     current.push_back(')');

//     // explore this choice
//     generateAll(current, ans, n);

//     // backtrack:
//     // remove ')' before returning
//     current.pop_back();
// }


// ---------------------------------------------------------
// Brute force wrapper
// ---------------------------------------------------------

// vector<string> generateParentheses(int n){

//     // stores all valid answers
//     vector<string> ans;

//     // stores the string currently being built
//     string current;


//     // start generating from an empty string
//     generateAll(current, ans, n);


//     return ans;
// }



// =========================================================
// 2. Optimal Backtracking Approach
// =========================================================
//
// Instead of generating invalid strings and checking them,
// we only make choices that can possibly lead to a valid
// parentheses string.
//
// Rules:
//
// 1. We can add '(' if:
//        openCount < n
//
//    Because we cannot use more than n opening brackets.
//
// 2. We can add ')' if:
//        openCount > closeCount
//
//    Because we cannot close a bracket unless there is an
//    unmatched opening bracket.
//
// This automatically prevents invalid strings.
//
// TC: O(number of valid parentheses strings * N)
// SC: O(N) recursion stack + current string
//
// Number of valid strings = Catalan number C_n.
// =========================================================


// =========================================================
// Function to generate valid parentheses strings
// =========================================================
//
// openCount  -> number of '(' currently used
// closeCount -> number of ')' currently used
// n          -> total number of '(' and ')' required
// current    -> current string being constructed
// ans        -> stores all valid strings
// =========================================================

void generate(vector<string>& ans,
              string& current,
              int openCount,
              int closeCount,
              int n){

    // base case:
    // total brackets used = 2*n
    if(openCount + closeCount == 2*n){

        // current is guaranteed to be valid
        // because we only allowed valid choices
        ans.push_back(current);

        return;
    }


    // -----------------------------------------------------
    // Choice 1: Add '('
    // -----------------------------------------------------
    //
    // We can add an opening bracket as long as
    // we have not already used n opening brackets.
    if(openCount < n){

        // choose '('
        current.push_back('(');


        // explore this choice
        // increase number of opening brackets
        generate(ans,
                 current,
                 openCount + 1,
                 closeCount,
                 n);


        // backtrack:
        // remove '(' so we can try another choice
        current.pop_back();
    }


    // -----------------------------------------------------
    // Choice 2: Add ')'
    // -----------------------------------------------------
    //
    // We can add ')' only when there is an unmatched '('.
    //
    // openCount > closeCount
    // means there is at least one '(' available to close.
    if(openCount > closeCount){

        // choose ')'
        current.push_back(')');


        // explore this choice
        // increase number of closing brackets
        generate(ans,
                 current,
                 openCount,
                 closeCount + 1,
                 n);


        // backtrack:
        // remove ')' before trying another path
        current.pop_back();
    }
}


// =========================================================
// Wrapper function
// =========================================================

vector<string> generateParentheses(int n){

    // stores all valid parentheses strings
    vector<string> ans;


    // stores the current string being constructed
    string current;


    // initially:
    // 0 opening brackets used
    // 0 closing brackets used
    generate(ans, current, 0, 0, n);


    // return all valid combinations
    return ans;
}


int main(){

    // number of pairs of parentheses
    int n = 3;


    // generate all valid combinations
    vector<string> ans = generateParentheses(n);


    // print all valid combinations
    for(auto& val: ans){
        cout << val << " ";
    }


    return 0;
}