// Print the fibonacci series upto Nth term

#include<iostream>
using namespace std;

// // 1. Iterative method method with extra array
// void fibonacci(int n){
//     int fib[n];
//     if(n<=0) return;
//     else{
//         fib[0] = 0;
//         fib[1] = 1;
//         for(int i=2; i<=n; i++){
//             fib[i] = fib[i-1] + fib[i-2];
//         }
//     }
//     cout << "Fibonacci series is: " << endl;
//     for(int i=0; i<n; i++){
//         cout << fib[i] << " ";
//     }
//     cout << endl;
// }

// // 2. Iterative method more optimized
// void fibonacci(int n){
//     int a = 0, b = 1;
//     if(n<=0) return ;
    
//     cout << "Fibonacci series is: " << endl;

//     if(n>=1){
//         cout << a << " ";
//     }
//     if(n>=2){
//         cout << b << " ";
//     }
//     for(int i=3; i<=n; i++){
//         int cur = a + b;
//         a = b;
//         b = cur;
//         cout << cur << " ";
//     }
// }

// 3. Recursive approach (Very bad)
int fibonacci(int n){
    if(n<=1) return n;

    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    int n = 10;

    // fibonacci(n);

    for(int i=0; i<n; i++){
        cout << fibonacci(i) << " " ;
    }


    return 0;
}