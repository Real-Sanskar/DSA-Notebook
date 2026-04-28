// Remove outermost parentheses from every primitive decomposition
// PRIMITIVE: Valid parentheses string that cannot be split into 2 non-empty valid strings 

#include<iostream>
#include<string>
#include<stack>
using namespace std;




// 1. Using Stack  (TC : O(N)    SC : O(N))

// Track when primitive starts 
// Track when primitive ends 
// store each primitive in temp string
// Remove first '(' and last ')' and concat into answer



// string remove_outer_parentheses(string str){
//     string temp = "";
//     string ans = "";
//     stack<char> s;

//     for(char ch:str){
//         temp += ch;

//         if(ch == '('){
//             s.push(ch);
//         }
//         else{
//             s.pop();
//         }

//         if(s.empty()){
//             ans += temp.substr(1,temp.size()-2);
//             temp = "";
//         }
//     }
//     return ans;
// }





// 2. Using counter (TC : O(N)   SC : O(1))

// Logic: Track balance (open count), skip when balance at boundary
// Key Insight:
// When balance = 0 before adding '(': it's outermost opening
// When balance = 1 before adding ')': it's outermost closing

string remove_outer_parentheses(string str){
    string ans = "";
    int depth = 0;

    for(char ch: str){
        if(ch == '('){
            if(depth > 0){
                ans += ch;
            }
            depth++;
        }
        else{
            depth--;
            if(depth > 0){
                ans += ch;
            }
        }

    }
    return ans;
}

int main(){
    string str = "(()())(())";

    cout << remove_outer_parentheses(str) << endl;

    return 0;
}