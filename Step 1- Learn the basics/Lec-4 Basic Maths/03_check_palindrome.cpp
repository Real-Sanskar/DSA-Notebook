#include<iostream>
using namespace std;

bool check_Palindrome(int n){
    int rev = 0;
    int duplicate = n;
    while(duplicate>0){
        int remainder = duplicate % 10;
        rev = (rev * 10) + remainder;
        duplicate = duplicate/10;
    }

    if(rev == n){
        return true;
    }
    else return false;

}

int main(){
    int n = 121;

    if(check_Palindrome(n)){
        cout << "Number is palindrome" << endl;
    }
    else {
        cout << "Number is not a palindrome" << endl;
    }



    return 0;
}