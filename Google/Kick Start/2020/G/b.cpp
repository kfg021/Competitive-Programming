/*
The constraints of this problem make it so the only valid paths are
along diagonals. We check all diagonals of the correct direction
and take the max to find the answer.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }

void solve(){
    int n;
    cin >> n;
    v2<int> g = fill(n, n, -1);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> g[i][j];
        }
    }

    ll ans = 0;
    for(int i = 0; i < n; ++i){
        ll diag = 0;
        int t = i;
        for(int j = n-1; j >= 0; --j){
            diag += g[t][j];
            --t;
            if(t==-1) break;
        }
        ans = max(ans, diag);
    }

    for(int i = n-1; i >= 0; --i){
        ll diag = 0;
        int t = i;
        for(int j = 0; j < n; ++j){
            diag += g[t][j];
            ++t;
            if(t==n) break;
        }
        ans = max(ans, diag);
    }

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
