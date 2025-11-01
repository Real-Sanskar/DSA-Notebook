#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// // 1. Brute force approach
// int* divisors(int n, int &size){
//     int *divisor = new int[n];

//     int count = 0;
//     for(int i=1; i<= n; i++){
//         if(n % i == 0){
//             divisor[count++] = i;
//         }
//     }
//     size = count;
//     return divisor;
// }

// int main(){
//     int n = 12;
//     int size;
//     int *divisor = divisors(n,size);

//     for(int i=0; i<size; i++){
//         cout << divisor[i] << " ";
//     }
//     cout << endl;

//     delete[] divisor;

//     return 0;
// }

// 2. Optimal approach
vector<int> divisors(int n){
    vector<int> divisor;
    
    int sqrtN = sqrt(n);

    for(int i=1; i<=sqrtN;i++){
        if(n % i == 0){
            divisor.push_back(i);
        }

        if(i != n/i){
            divisor.push_back(n/i);
        }
    }
    return divisor;
}

int main(){
    int n = 12;
    vector<int> divisor = divisors(n);

    for(auto val: divisor){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
