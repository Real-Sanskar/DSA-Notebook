#include<iostream>
#include<cmath>
using namespace std;

// // 1. Brute force approach
// bool checkPrime(int n){
//     int count = 0;
//     for(int i=1; i<=n; i++){
//         if(n % i == 0){
//             count++;
//         }
//     }
//     if(count == 2){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

// 2. Optimal approach
bool checkPrime(int n){
    int count = 0;
    int sqrtN = sqrt(n);
    for(int i=1; i<=sqrtN; i++){
        if(n % i == 0){
            count++;
        }

        if(i != n/i){
            count++;
        }
    }
    return count == 2? true: false;

}


int main(){
    int n= 3;

    if(checkPrime(n)){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }


    return 0;
}