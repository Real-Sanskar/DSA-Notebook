#include<iostream>
using namespace std;

int main(){
    int n=6;
    int Upper_space = 0;
    for(int i=0; i<n; i++){
        //star
        for(int j=0; j<n-i; j++){
            cout << "*";
        }
        //space
        for(int j=0; j<Upper_space; j++){
            cout << " ";
        }
        //star
        for(int j=0; j<n-i; j++){
            cout << "*";
        }
        cout << endl;
        Upper_space += 2;

    }
    int Lower_space = 2*n - 2;
    for(int i=0; i<n; i++){
        //star
        for(int j=0; j<=i; j++){
            cout << "*";
        }
        //space
        for(int j=0; j< Lower_space; j++){
            cout << " ";
        }
        //star
        for(int j=0; j<=i; j++){
            cout << "*";
        }
        Lower_space -= 2;
        cout << endl;
    }

    return 0;
}