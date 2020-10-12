/*
We can determine the winner by using these two rules:
    * If n is odd and there is at least one odd digit with an odd index,
    then player 1 wins. Otherwise, player 2 wins.
    * If n is even and there is at least one even digit with an even index,
    then player 2 wins. Otherwise, player 1 wins.
Note: "odd" and "even" indices refer to 1-based indexing, as stated
in the problem. In the code, I use 0-based indexing, so some things are
reversed.
*/

#include <bits/stdc++.h> 
using namespace std;

void solve(){
    int n;
    string s;
    cin>>n>>s;

    if(n%2==0){
        bool even = false;
        for(int i = 1; i < n; i+=2){
            if(s[i]%2==0) even=true;
        }

        if(even) cout << "2\n";
        else cout << "1\n";
    }
    else{
        bool odd = false;
        for(int i = 0; i < n; i+=2){
            if(s[i]%2==1) odd=true;
        }

        if(odd) cout << "1\n";
        else cout << "2\n";
    }
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