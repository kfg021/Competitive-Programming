#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){
    return v2<T>(r, vector<T>(c, t));
}
#define F first
#define S second

ll solve(ll x, ll y){
    ll mod = x*y;
    ll ans = (((-x-y) % mod) + mod) % mod;
    if(ans == 0){
        ans = x*y;
    }
    return ans;
}

void solve(){
    ll x, y;
    cin >> x >> y;
    cout << solve(x, y) << "\n";
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
