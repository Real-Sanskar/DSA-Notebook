// Print N to 1 using recursion
#include<iostream>
using namespace std;

// // 1. First method (Forward recursion)
// void printNum(int i, int n){
//     if(i<1) return;
//     cout << i << endl;
//     printNum(i-1,n);
// }

void printNum(int i, int n){
    if(i>n) return;
    printNum(i+1,n);
    cout << i << endl;
}


int main(){
    int n = 3;

    // printNum(n,n);
    printNum(1,n);

    return 0;
}