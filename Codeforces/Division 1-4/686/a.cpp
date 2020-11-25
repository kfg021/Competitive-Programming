/*
A simple construction for this problem is to just print [2, 3, 4, ..., n, 1].
*/

#include <bits/stdc++.h> 
using namespace std;

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n-1; ++i){
        cout << i+2 << " ";
    }
    cout << "1\n";
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