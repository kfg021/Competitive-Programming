/*
We can solve this with a dp where dp[i][j] := the number of valid answers when 
y[i] = {false if j = 0, true if j = 1}.
For the transition, we can consider both possibilities for x[i], true and
false, in constant time.

The answer will be dp[0][0] + dp[0][1].
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){
    return v2<T>(r, vector<T>(c, t));
}

int n;
vector<string> s;
v2<ll> dp;

ll f(int i, bool b){
    // # of ways when y[i] = b
    if(i==n){
        return b;
    }
    if(dp[i][b] != -1){
        return dp[i][b];
    }

    ll ans = 0;
    for(bool x : {true, false}){
        if(s[i]=="AND"){
            ans += f(i+1, b & x);
        }
        else{
            ans += f(i+1, b | x);
        }
    }
    return dp[i][b] = ans;
}

void solve(){
    cin >> n;
    s = vector<string>(n);
    for(int i = 0; i < n; ++i){
        cin >> s[i];
    }

    dp = fill(n+1, 2, -1LL);
    ll ans = f(0, false) + f(0, true);
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}