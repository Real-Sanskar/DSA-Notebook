#include<bits/stdc++.h>
using namespace std;

int amstrong_Num(int n){
    int dup = n;
    int count = to_string(n).length();
    // while(dup>0){
    //     count++;
    //     dup /= 10;
    // }
    
    int sum = 0;
    dup = n;
    while(dup>0){
        int remainder = dup % 10;

        sum += round(pow(remainder,count));
        dup /= 10;
    
    }
    return sum == n? true:false;

}

int main(){
    int n = 153;

    amstrong_Num(n);


    return 0;
}