/*
A 1-stair staircase is clearly nice. We can then see that a 3-stair staircase
is also nice, since it consists of two squares of size 1x1 and one square
of size 2x2. We can see that a 7-stair staircase is nice by a similar
argument. In fact, it turns out that nice staicases must be of the form
2n + 1, where n is a whole number. We will use this to answer the
question with a greedy approach, always taking the smallest possible
staircase until we exceed x.
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

void solve(){
    ll x;
    cin >> x;

    ll n = 1;
    int ans = 0;
    while(true){
        x -= (n*(n+1))/2;
        if(x < 0) break;
        n = 2*n+1;
        ++ans;
    }

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