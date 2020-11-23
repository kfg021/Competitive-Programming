/*
(Solved after contest.)

If a > b*c, the answer will be -1.
Otherwise, a <= b*c. Notice that the minimum answer must be at t<=c. This
is because we know there were at are at least c healing operations from
t=1 to t=c, resulting in b*c points of healing. This is greater than or
equal to a by assumption. 

Consider time values that are multiples of d. It must be the case that
the maximum possible health values at these times create a unimodal function
(that is, they increase until a point and then decrease). The values will
increase initially, but eventually the healing will overtake the damage and
they will begin to decrease.

The max health for the nth health decrease can be represented as 
    a*n - b*d * n*(n-1)/2 .
Given this formula, we can do a ternary search on the range (1, c) to find the
maximum possible answer.
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

ll a, b, c, d;

ll value(ll n){ 
    return a*n - b*d*(n*(n-1))/2;
}

void solve(){
    cin >> a >> b >> c >> d;

    if(a > b*c){
        cout << "-1\n";
    }
    else{
        ll lo = 1;
        ll hi = (c+d-1)/d;
        while(lo < hi) {
            ll mid = (hi+lo)/2;
            ll diff = value(mid+1) - value(mid);
            if(diff <= 0) {
                hi = mid;
            }
            else {
                lo = mid+1;
            }
        }
        cout << value(lo) << "\n";
    }
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