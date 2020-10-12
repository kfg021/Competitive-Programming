/*
For any a, the number of b's such that a*b < n is floor((n-1)/a).
We dont need to worry about c because it is uniquely determined by our
choices of a and b. We can iterate over all possible a's from 1 to n to
find our answer.
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;

    ll ans = 0;
    for(int i = 1; i <= n; ++i){
        ans += (n-1)/i;
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}