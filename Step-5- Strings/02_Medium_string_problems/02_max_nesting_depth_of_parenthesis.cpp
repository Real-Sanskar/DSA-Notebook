// Given a valid parenthesis string str, return the nesting depth of str
// Nesting depth is the maximum number of nested parenthesis

#include<iostream>
using namespace std;


// Optimal (Using counter)  (TC : O(N))

// Each opening bracket indicates going deeper into a new level of nesting.
// Each closing bracket signals returning to the previous level of nesting.
// By tracking how deep we go at each step, we can monitor the peak nesting level.

int max_nesting_depth(string str){
    int count = 0, maxDepth = 0;
    for(char ch : str){
        if(ch == '('){
            count++;
        }
        else if(ch == ')'){
            count--;
        }
        maxDepth = max(maxDepth, count);
    }
    return maxDepth;
}

int main(){
    string str = "(1)+((2))+(((3)))";

    cout << max_nesting_depth(str) << endl;

    return 0;
}