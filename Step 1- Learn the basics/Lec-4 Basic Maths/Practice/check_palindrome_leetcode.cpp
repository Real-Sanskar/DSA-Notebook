#include<iostream>
using namespace std;

bool check_palindrome(int n){
    int rev = 0;
    int dup = n;

    if(n<0) return false;

    while(n>0){
        int remainder = n % 10;
        rev = rev * 10 + remainder;

        n = n /10;
    }
    if(dup == rev){
        return true;
    }
    else{
        return false;
    }

}

int main(){
    int n = 123;

    if(check_palindrome(n)){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }

    

    return 0;
}