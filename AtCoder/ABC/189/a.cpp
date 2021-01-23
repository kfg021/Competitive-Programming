/*
Check if all three positions have equal characters.
*/

#include <bits/stdc++.h> 
using namespace std;

void solve(){
    string s;
    cin >> s;
    bool ans = (s[0]==s[1] && s[0]==s[2]);
    if(ans){
        cout << "Won\n";
    }
    else{
        cout << "Lost\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}