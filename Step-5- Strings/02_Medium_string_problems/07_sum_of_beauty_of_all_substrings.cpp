// Beauty of string = (max freq char) - (min freq char) among chars that appear in string

// Return sum of beauty of all substings of str

#include<iostream>
#include<climits>
using namespace std;



// Approach (TC : O(N*N)   SC : O(1))

// generate all substrings
// Store freq of all chars in substring
// find minFreq and maxFreq in the substring
// find beauty
// add to totalBeauty

// ** make sure to find minFreq only for freq > 0 otherwise if 0 is encoutered first min will be 0 and acutal char freq will not be stored

int beautySum(string str){
    int n = str.size();
    int totalBeauty = 0;

    for(int i=0; i<n; i++){
        int freq[26] = {0};
        for(int j=i; j<n; j++){
            freq[str[j] - 'a']++;

            int minFreq = INT_MAX;
            int maxFreq = 0;
            for(int k=0; k<26; k++){
                if(freq[k] > 0){
                    minFreq = min(minFreq, freq[k]);
                    maxFreq = max(maxFreq, freq[k]);
                }
            }

            totalBeauty += maxFreq - minFreq;
        }
    }
    return totalBeauty;
}

int main(){
    string str = "aabcb";

    cout << beautySum(str) << endl;

    return 0;
}