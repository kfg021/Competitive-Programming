/*
For i from 1 to N we need to check two conditions:
    sum(j=1, K)(T_(i,j)) <= M
    Q_i <= 10

This can be done using nested for loops.
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    int ans = 0;
    for(int i = 0; i < n; ++i){
        int tot = 0;
        for(int j = 0; j < k; ++j){
            int t; cin >> t;
            tot += t;
        }
        int q; cin >> q;
        if(tot >= m && q <= 10) ++ans;
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
