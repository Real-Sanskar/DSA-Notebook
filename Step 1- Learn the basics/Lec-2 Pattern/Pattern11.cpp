#include<iostream>
using namespace std;

int main(){
    int n=5;

    int val = 1;
    for(int i=0; i<n; i++){
        if(i%2 == 0) val = 1;
        else val = 0;

        for(int j=0; j<=i; j++){
            cout << val << " ";
            val = 1 - val;
        }
        cout << endl;
    }
    return 0;
}