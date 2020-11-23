/*
Let f(l, r) represent the number of boring numbers from l to r inclusive.
Using inclusion-exclusion, f(l, r) = f(0, r) - f(0, l-1). 
All that remains is to calculate f(0, x) for any x.
Let D be the number of digits in x. For d from 1 to D-1, the number of boring
d-digit numbers is 5^d, since there are 5 possible choices in each position.
For the number of D digit numbers, we use digit dynamic programming.
Our state is dp[i][edge] = the number valid of boring numbers using up to the
ith digit, and whether we are on the "edge" (If we are constrained in terms
of the digits we can use).
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }

int len;
v2<ll> dp;

ll f(int ind, bool edge, string& s){
    if(ind==len){
        return 1;
    }
    if(dp[ind][edge] != -1){
        return dp[ind][edge];
    }
    if(edge){
        dp[ind][edge] = 0;
        for(int i = (ind+1)%2; i < s[ind]-'0'; i+=2){
            dp[ind][edge] += f(ind+1, 0, s);
        }
        if((ind+1)%2 == (s[ind]-'0')%2){
            dp[ind][edge] += f(ind+1, 1, s);
        }
        return dp[ind][edge];
    }
    else{
        return dp[ind][edge] = 5LL * f(ind+1, edge, s);
    }
}

ll num(ll r){
    string s = to_string(r);
    len = s.size();
    dp = fill(len, 2, -1LL);

    ll ans = 0;
    ll p5 = 5;
    for(int l = 1; l < len; ++l){
        ans += p5;
        p5 *= 5;
    }

    ll last = 0;
    for(int i = 1; i < s[0]-'0'; i+=2){
        last += f(1, 0, s);
    }
    if((s[0]-'0')%2 == 1){
        last += f(1, 1, s);
    }

    ans += last;
    return ans;
}

void solve(){
    ll l, r;
    cin >> l >> r;

    ll ans = num(r) - num(l-1);
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for(int i = 1; i <= T; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
