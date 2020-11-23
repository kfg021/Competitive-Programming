/*
We will solve each portion of the motion independently, and then combine
the answers. Maintain two values, greatest and end, representing the
maximum value in this sequence and the ending point of this sequence,
respectively. To construct the final answer, take the maximum over the
greatest values on all portions of the path.
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    vector<ll> greatest(n), end(n);
    end[0] = a[0];
    greatest[0] = max(0, a[0]);
    for(int i = 1; i < n; ++i){
        end[i] = end[i-1] + a[i];
        greatest[i] = max(greatest[i-1], end[i-1]);
    }
    for(int i = 1; i < n; ++i){
        end[i] += end[i-1];
    }

    ll ans = -1e18;
    for(int i = 0; i < n; ++i){
        ll elem = i-1 >= 0 ? end[i-1] : 0;
        ans = max(ans, elem+greatest[i]);
    }
    ans = max(ans, end[n-1]);
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}