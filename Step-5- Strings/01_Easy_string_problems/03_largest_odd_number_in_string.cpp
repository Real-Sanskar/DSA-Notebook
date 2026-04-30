// Given a string, representing a large integer
// Return largest-valueed odd integer (as string) that is substring of give string

// NOTE: Number returned should NOT have leading 0s, but input string may have leading 0s

#include<iostream>
#include<string>
using namespace std;



// Greedy (Rightmost Odd Digit)    (TC: O(N)   SC: O(1))

// number is odd -> last digit is odd
// Remove all leading 0s
// To maximize, include as many digits as possible
// return substring from first valid to that position
 
string largest_odd_number(string str){
    int n = str.length();
    int st = 0, end = n-1;
    string ans = "";

    while(str[st] == '0'){
        st++;
    }
    while(end >= st){
        if((str[end]-'0')%2 == 1){
            break;
        }
        end--;
    }
    ans = str.substr(st, end-st+1);

    return ans;
}

int main(){
    string str = "2468";

    cout << largest_odd_number(str) << endl;

    return 0;
}