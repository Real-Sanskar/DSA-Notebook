// Counts digits in number
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

// BRUTE FORCE APPROACH
// int countDigits(int n){
//     int count = 0;

//     while(n>0){
//         count++;

//         n /= 10;
//     }

//     return count;
// }

//OPTIMAL APPROACH
int countDigits(int n){
    int count = (int)(log10(n) + 1);

    return count;
}

int main(){
    int n = 12345;

    cout << countDigits(n) << endl;


    return 0;
}