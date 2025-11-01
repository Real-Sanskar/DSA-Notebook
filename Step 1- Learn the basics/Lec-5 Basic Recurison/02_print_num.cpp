// Print numbers from 1 to N
#include<iostream>
using namespace std;

void printNum(int n, int i){
    if(i>n) return;

    cout << i << endl;
    printNum(n,i+1);
}       

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;

    printNum(n,1);

    return 0;
}