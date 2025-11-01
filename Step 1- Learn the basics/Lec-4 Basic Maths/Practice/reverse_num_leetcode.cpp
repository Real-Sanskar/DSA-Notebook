#include<iostream>
using namespace std;

int reverseNum(int n){
    int rev = 0;
    while(n!=0){
        int rem = n % 10;
        n = n/10;

        if((rev > INT32_MAX/10   ) || (rev == INT32_MAX/10 && rem > 7)){
            return 0;
        }
        if((rev < INT32_MIN/10) || (rev == INT32_MIN/10 && rem < -8)){
            return 0;
        }
        
        rev = rev * 10 + rem;
    }
    return rev;
}

int main(){
    int n = 123;

    cout << reverseNum(n) << endl;

    return 0;
}