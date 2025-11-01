#include<iostream>
using namespace std;


int reverseNum(int n){
    int rev = 0;
    while(n>0){
        int remainder = n % 10;
        rev = (rev*10) + remainder;

        n = n/10;
    }
    return rev;
}

int main(){
    int n = 1221;

    cout << reverseNum(n) << endl;

    return 0;
}