/*
We can try both situations and take the min. In the first case, we pay
a total cost of k+n to restart and finish the game. Or, we can pay a cost
of 2(k-s)+n to return to the sword, pick it up, and finish.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, k, s;
    cin >> n >> k >> s;
    ll a = k+n, b = 2LL*(k-s) + n;
    ll ans = min(a, b);
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
