#include<iostream>
#include<climits>
using namespace std;


// helper function to recursively convert the numeric part of string
// into an integer
//
// i    -> current index in string
// sum  -> number formed so far
// sign -> 1 for positive, -1 for negative
int helper(string s, int i, int sum, int sign){

    // stop when we reach the end of string
    // or current character is not a digit
    if(i >= s.size() || !isdigit(s[i])){
        return (int)(sign * sum);
    }


    // convert current character from ASCII character to integer
    int digit = s[i] - '0';


    // check if adding another digit will cause integer overflow
    //
    // Example:
    // sum = 214748365
    // sum * 10 will exceed INT_MAX
    if(sum > INT_MAX/10){
        return (sign == 1) ? INT_MAX : INT_MIN;
    }


    // special case when sum is exactly INT_MAX/10
    //
    // INT_MAX = 2147483647
    // INT_MAX/10 = 214748364
    //
    // The last allowed digit is 7 for positive numbers.
    // If digit > 7, the value will exceed INT_MAX.
    //
    // For negative numbers, INT_MIN = -2147483648,
    // but using the same condition is safe here because
    // we clamp the result to INT_MIN.
    if(sum == INT_MAX/10 && digit > 7){
        return (sign == 1) ? INT_MAX : INT_MIN;
    }


    // add current digit to the number formed so far
    //
    // Example:
    // sum = 123, digit = 4
    // new sum = 123 * 10 + 4 = 1234
    sum = sum * 10 + digit;


    // recursively process the next character
    return helper(s, i+1, sum, sign);
}


// function to convert string into integer
int atoi(string s){

    // start from first character
    int i = 0;


    // ignore leading spaces
    //
    // Example:
    // "   -1234"
    //      ^
    //      i
    while(i < s.size() && s[i] == ' ')
        i++;


    // sign is positive by default
    int sign = 1;


    // check if the current character is '+' or '-'
    if(i < s.size() && (s[i] == '-' || s[i] == '+')){

        // set sign according to the character
        sign = (s[i] == '-') ? -1 : 1;

        // move to the first digit
        i++;
    }


    // start recursive conversion
    //
    // i    -> first digit
    // 0    -> number formed so far
    // sign -> sign of final number
    return helper(s, i, 0, sign);
}


int main(){

    // string containing leading spaces and a negative number
    string s = "  -1234";


    // convert string to integer and print result
    cout << atoi(s) << endl;


    return 0;
}