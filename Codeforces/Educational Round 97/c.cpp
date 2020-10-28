/*
The first observation to make is that we will always take dishes out of
the oven such that their t values are non-decreasing. If we were to take out
a later dish before an earlier dish, we could swap them and the unpleasant
value will either decrease or stay the same. Because of this we can sort t
and solve the problem with dynamic programming. 
Our state will be:
    dp[t][i] = the minimum unplesantness we can obtain at time t up to index i.

The maximum time we could possibly need is 2n, because in the worst case we
will take out the first dish at t=n and the last at t=2n. Therefore, the
final answer will be dp[2n][n-1].
*/

#include <bits/stdc++.h> 
using namespace std;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }

int n;
vector<int> t;
v2<int> dp;

int f(int time, int ind){
    if(ind==-1){
        return 0;
    }
    else if(time==0){
        return 1e9;
    }
    if(dp[time][ind]!=-1) return dp[time][ind];

    int a = f(time-1, ind);
    int b = f(time-1, ind-1) + abs(time-t[ind]);
    dp[time][ind] = min(a, b);
    return dp[time][ind];
}

void solve(){
    cin >> n;
    t = vector<int>(n);
    for(int i = 0; i < n; ++i) cin >> t[i];
    sort(t.begin(), t.end());

    dp = fill(2*n+1, n, -1);

    int ans = f(2*n, n-1);
    cout << ans << "\n";
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