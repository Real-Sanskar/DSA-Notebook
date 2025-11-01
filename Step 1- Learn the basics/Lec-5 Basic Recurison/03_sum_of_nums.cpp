// Print the sum of first N natural numbers 

#include<iostream>
using namespace std;


// // Using loop
// void printSum(int n){
//     int sum=0;
//     for(int i=1; i<=n; i++){
//         sum+= i;
//     }
//     cout << sum << endl;
// }

// // 2. Using Formula
// void printSum(int n){
//     int sum = n*(n+1)/2;
//     cout  << sum << endl;
// }

// // 3. Recursion(Parameterized way)
// void printSum(int i, int sum){
//     if(i<1){
//         cout << sum << endl;
//         return;
//     }
//     printSum(i-1,sum+i);
// }

// 4. Recursion (Function Way
int printSum(int n){
    if(n==0){
        return 0;
    }
    return n + printSum(n-1);
}

int main(){
    int n = 4;

    // printSum(n);

    // printSum(n,0);

    cout << printSum(n) << endl;

    return 0;
}