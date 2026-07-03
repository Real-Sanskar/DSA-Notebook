#include<iostream>
#include<unordered_set>
using namespace std;


// int countSubstrings(string str, int k){
//     int n = str.size();

//     int count = 0;
//     for(int i=0; i<n; i++){
//         for(int j=i; j<n; j++){
//             unordered_set<char> distinct;

//             for(int l=i; l<=j; l++){
//                 distinct.insert(str[l]);
//             }
//             if(distinct.size() == k){
//                 count++;
//             }   
//         }
//     }
//     return count;
// }



// int countSubstrings(string str, int k){
//     int n = str.size();
//     int count = 0;

//     for(int i=0; i<n; i++){
//         int freq[26] = {0};
//         int distinct = 0;

//         for(int j=i; j<n; j++){
//             if(freq[str[j] - 'a'] == 0){
//                 distinct++;
//             }
//             freq[str[j] - 'a']++;

//             if(distinct == k){
//                 count++;
//             }

//             if(distinct > k){
//                 break;
//             }
//         }
//     }
//     return count;
// }



int atMost(string str, int k){
    if(k <= 0) return 0;

    int n = str.size();

    int left = 0;
    int distinct = 0;
    int count = 0;
    int freq[26] = {0};

    for(int right=0; right<n; right++){
        if(freq[str[right] - 'a'] == 0){
            distinct++;
        }
        freq[str[right] - 'a']++;

        while(distinct > k){
            freq[str[left] - 'a']--;

            if(freq[str[left] - 'a'] == 0){
                distinct--;
            }
            left++;
        }

        count += right - left + 1;
    }
    return count;
}

int countSubstrings(string str, int k){
    return atMost(str,k) - atMost(str,k-1);
}


int main(){
    string str = "aabaa";
    int k = 1;

    cout << countSubstrings(str,k) << endl;

    return 0;
}