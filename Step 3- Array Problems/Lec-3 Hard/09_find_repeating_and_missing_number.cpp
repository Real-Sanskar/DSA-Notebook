// given an array of size n, containing numbers from (1 to n)
// One is repeating and other is missing, find both


#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;



// 1. Brute force approach (TC : O(N*N)    SC : O(1))

// LOGIC : 
// for each number from 1 to n, check its freq in array
// if (freq == 0) -> missing
// if (freq == 2) -> repeating

// pair<int,int> find_num(vector<int> &arr){
//     int n = arr.size();

//     pair<int,int> ans = {0,0};

//     for(int i=1; i<=n; i++){
//         int count = 0;
//         for(int j=0; j<n; j++){
//             if(arr[j] == i){
//                 count++;
//             }
//         }
//         if(count == 2){
//             ans.first = i;
//         }
//         else if(count == 0){
//             ans.second = i;
//         }

//         if(ans.first != 0 && ans.second != 0) break;
//     }

//     return ans;
// }





// 2. Better approach (Hashing) (TC : O(N)    SC : O(N))

// LOGIC :
// traverse array, store element and frequency in HashMap
// if (freq == 0) -> missing
// if (freq == 2) -> repeating 

// pair<int,int> find_num(vector<int> &arr){
//     int n = arr.size();

//     unordered_map<int,int> freq;
//     pair<int,int> ans;

//     for(int i=0; i<n; i++){
//         freq[arr[i]]++;
//     }
//     for(int i=1; i<=n; i++){
//         if(freq[i] == 2){
//             ans.first = i;
//         }
//         else if(freq[i] == 0){
//             ans.second = i;
//         }
//     }
//     return ans;
// }




// 3. Optimal (Math)  (TC : O(N)    SC : O(1))

// LOGIC : 
// Find values of S and Sn, calculate S - Sn
// Find values of S2 and S2n, calculate S2 - S2n
// we will have values of x + 7 and x - y, solving find x and y

// pair<int,int> find_num(vector<int> &arr){
//     int n = arr.size();

//     pair<int,int> ans;

//     // S - Sn = x - y
//     // S2 - S2n

//     long long SN = (n*(n+1))/2;
//     long long S2N = (n*(n+1)*(2*n+1))/6;

//     long long S = 0, S2 = 0;
//     for(int i=0; i<n; i++) {
//         S += arr[i];
//         S2 += (long long)arr[i] * (long long)arr[i];
//     }

//     long long val1 = S - SN;
//     long long val2 = S2 - S2N;
//     val2 = val2 / val1;
//     long long x = (val1 + val2)/2;
//     long long y = x - val1;

//     ans = {(int)x, (int)y};
//     return ans;
// }





// 4. Optimal (XOR)  (TC : O(N)    SC : O(1))

// LOGIC : 
// x ^ y = (arr[i]) ^ (1^2^..... n) = num
// find a differentiating bit in num; first from right
// put them into 2 parts (that bitNo either 0 or 1) & XOR
// identify which one is missing and which one is repeating

pair<int,int> find_num(vector<int> &arr){
    int n = arr.size();

    int xr = 0;
    for(int i=0; i<n; i++){
        xr = xr ^ arr[i];

        xr = xr ^ (i+1);
    }

    int bitNo = 0;
    while(1){
        if((xr & (1 << bitNo)) != 0){
            break;
        }
        bitNo++;
    }

    int zero = 0, one = 0;
    for(int i=0; i<n; i++){
        if((arr[i] & (1 << bitNo)) != 0){
            one = one ^ arr[i];
        }
        else{
            zero = zero ^ arr[i];
        }
    }
    for(int i=1; i<=n; i++){
        if((i & (1 ^ bitNo)) != 0){
            one = one ^ i;
        }
        else{
            zero = zero ^ i;
        }
    }

    int cnt = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == zero) cnt++;
    }
    if(cnt == 2) return {zero,one};

    return {one,zero};
}

int main(){
    vector<int> arr = {3,1,2,5,3};

    pair<int,int> ans = find_num(arr);

    cout << ans.first << " " << ans.second << endl;

    return 0;
}