// Map hashing
// Character hashing

#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    string s;
    cin >> s;

    // pre-storing
    unordered_map<char,int> m;
    for(int i=0; i<s.size(); i++){
        m[s[i]]++;
    }

    // iterating over map
    // for(auto val:m){
    //     cout << val.first << " " << val.second << endl;
    // }

    // fetching
    int q;
    cin >> q;
    while(q--){
        char c;
        cin >> c;

        cout << m[c]  << endl;
    }

    return 0;
}