#include<iostream>
#include<algorithm>
using namespace std;

// // 1. Brute force approach
// // TC: O(min(n1,n2))
// int GCD(int n1, int n2){
//     int common_divisor = 0;

//     for(int i=1; i<= min(n1,n2); i++){
//         if(n1 % i == 0 && n2 % i == 0){
//             common_divisor = i;
//         }
//     }

//     return common_divisor;

// }

// // 2. Better approach, better chance to get largest value in reverse order for large values
// // TC: O(min(n1,n2))
// int GCD(int n1, int n2){
//     for(int i=min(n1,n2); i>0; i--){
//         if(n1 % 2 == 0 && n2 % 2 == 0){
//             return i;
//         }
//     }
// }

// 3. Optimal approach (Euclidean algorithm)
int GCD(int n1,int n2){
    while(n1>0 && n2>0){
        if(n1>n2){   
            n1 = n1 % n2;
        }
        else{
            n2 = n2 % n1;
        }
    }
    if(n1 == 0){
        return n2;
    }
    else return n1;
}


int main(){
    int n1 = 4, n2 = 12;

    cout << "Greatest common divisor = " <<GCD(n1,n2) << endl;


    return 0;
}