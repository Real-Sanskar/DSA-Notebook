// Implement the function myAtoi(s) which converts the given string s to a 32-bit signed integer

#include<iostream>
#include<climits>
using namespace std;


// (TC : O(N)  SC : O(1))

// 1. Skip leading whitespaces
// 2. Determine the sign, if neither + not -, sign stays positive
// 3. Read digits and build number
// 4. OVERFLOW CHECK (before updating)
// 5. Update result
// 6. Apply sign and return

int myAtoi(string str){
    int n = str.size();
    int i = 0;

    while(i<n && str[i] == ' '){
        i++;
    }
    if(i >= n) return 0;

    int sign = 1;
    if(str[i] == '-'){
        sign = -1;
        i++;
    }
    else if(str[i] == '+'){
        sign = +1;
        i++;
    }

    int result = 0;
    while(i<n && isdigit(str[i])){
        int digit = str[i] - '0';

        if(result > INT_MAX/10){
            return (sign == 1)?INT_MAX: INT_MIN;
        }
        if(result == INT_MAX/10 && digit > 7){
            return (sign == 1)? INT_MAX: INT_MIN;
        }

        result = result * 10 + digit;
        i++;
    }
    return result;
}

int main(){
    string str = "4193 with words";

    cout << myAtoi(str) << endl;

    return 0;
}