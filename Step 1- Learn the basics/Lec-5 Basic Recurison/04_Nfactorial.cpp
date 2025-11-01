// Find factorial of a number n

#include<iostream>
using namespace std;


// // Iterative method
// int factorial(int n){
//     int fact = 1;
//     for(int i=1; i<=n; i++){
//         fact *= i;
//     }
//     return fact;
// }

// Recursive method
int factorial(int n){
    if(n==1) return 1;

    return n*factorial(n-1);
}

int main(){
    int n = 5;

    cout << factorial(n) << endl;


    return 0;
}