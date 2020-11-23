/*
We can determine whether we can kill all enimies given a specific cooldown time t.
Sort the ships by arrival time, and shoot them down one by one. If d seconds elapses
from when we first see a ship, the answer will be false. Otherwise, it will be true.
Using the above function, we can binary search the answer. We will return once we get
close enough to it (within some epsilon).
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define F first
#define S second

const ld EPS = 1e-9;

int n, d;
vector<pair<ll, ll>> a;

bool works(ld x){
    ld last = -x;
    for(int i = 0; i < n; ++i){
        ll start = a[i].S, end = a[i].F;
        if(last+x > end) return false;
        else{
            last = max(last+x, (ld)start);
        }
    }
    return true;
}

void solve(){
    cin >> n >> d;
    a = vector<pair<ll, ll>>(n);
    for(int i = 0; i < n; ++i){
        int c;
        cin >> c; 
        a[i].F = c+d;
        a[i].S = c;
    }
    sort(a.begin(), a.end());


    ld lo = 1e-9;
    ld hi = 1e18;
    ld ans = -1;
    while(hi-lo > EPS){
        ld mid = (lo+hi)/2;
        if(works(mid)){
            ans = mid;
            lo = mid;
        }
        else{
            hi = mid;
        }
    }    
    cout << fixed << setprecision(9) << ans << '\n';
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
