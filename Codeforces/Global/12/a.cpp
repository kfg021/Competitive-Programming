/*
Since "trygub" is not in alphabetical order, we can just sort the string.
This will ensure that it does not appear as a subsequence.
*/

#include <bits/stdc++.h> 
using namespace std;

void solve(){
    int n;
    string s;
    cin >> n >> s;

    sort(s.begin(), s.end());
    cout << s << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for(int i = 0; i < T; ++i){
        solve();
    }
    return 0;
}