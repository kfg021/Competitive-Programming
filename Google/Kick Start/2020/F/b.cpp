/*
We can solve this problem with a greedy approach. Sort the intervals
by start time. If we reach an interval that is not yet covered by the 
robot, deploy the robot at the start of this interval and keep
deploying it until the interval ends. If we reach an interval that is
covered only until a certain point, start the robot from this point,
and continue it until the end of the interval.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define F first
#define S second

void solve(){
    int n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> t(n);
    for(int i = 0; i < n; ++i){
        cin >> t[i].F >> t[i].S;
    }
    sort(t.begin(), t.end());

    int ans = 0;
    ll last = 0;
    for(int i = 0; i < n; ++i){
        if(t[i].F > last) last = t[i].F;
        ll deps = (t[i].S-last + k-1)/k;
        last += deps*k;
        ans += deps;
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