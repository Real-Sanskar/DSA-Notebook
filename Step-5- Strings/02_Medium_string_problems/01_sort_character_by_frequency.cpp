// given a string s, sort in descending order of frequency of characters
// if freq is same, sort in alphabetical order

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;




bool comparator(pair<char,int> p1, pair<char,int> p2){
    if(p1.second == p2.second){
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}


//  Only lowercase characters (TC : O(N + k*logk)   SC : O(1))

// 1. Count frequency of each character
// 2. Collect unique characters
// 3. Sort them using CUSTOM COMPARATOR:
//    → Primary: higher frequency first
//    → Secondary: alphabetical order


// vector<char> sort_by_freq(string str){
//     pair<char,int> freq[26];
//     vector<char> ans;

//     for(int i=0; i<26; i++){
//         freq[i] = {i + 'a', 0};
//     }

//     for(char ch: str){
//         freq[ch - 'a'].second++;
//     }

//     sort(freq, freq + 26, comparator);

//     for(int i=0; i<26; i++){
//         if(freq[i].second > 0) ans.push_back(freq[i].first);
//     }
//     return ans;
// }



// Both uppercase and lowercase characters 

vector<char> sort_by_freq(string str){
    unordered_map<char,int> freq;

    for(char ch: str){
        freq[ch]++;
    }

    vector<pair<char,int>> vec(freq.begin(),freq.end());

    sort(vec.begin(),vec.end(), comparator);

    vector<char> ans;
    for(auto &p : vec){
        ans.push_back(p.first);
    }
    return ans;
}

int main(){
    string str = "written";

    vector<char> result = sort_by_freq(str);

    for(char ch: result){
        cout << ch << " ";
    }
    cout << endl;

    return 0;
}