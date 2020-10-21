/*
This solution only passes the first two test sets, where W <= 1000 and n <= 10^9.

It turns out that it is optimal to only check the locations with the starting
weights. During the contest, I checked some unnessisarily location, but
this is irrelevant since we take the min over all possible answers.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int w, n;
vector<int> x;

ll cost(int l){
    ll ans = 0;
    for(int j = 0; j < w; ++j){
        int a = abs(x[j]-l);
        int b = n-abs(x[j]-l);
        ans += min(a, b);
    }
    return ans;
}

void solve(){
    cin >> w >> n;

    x = vector<int>(w);
    for(int i = 0; i < w; ++i){
        cin >> x[i];
        --x[i];
    }

    ll ans = 1e18;
    for(int i = 0; i < w; ++i){
        ans = min(ans, cost(x[i]));
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
