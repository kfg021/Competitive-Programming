/*
Consider the two components of the second constraint: a+b and -(c+d).
Let's iterate over the possible values of a+b. If a+b = x, then c+d
must equal x - k. We will use a function ways(n, x) to determine the
number of (a, b) such that 1 <= (a, b) <= n and a+b = x. The answer will
be ways(n, x) * ways(n, x-k), since the values for each component are
independent.

Take the sum over all possible values of a+b for the final answer.
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

ll ways(int n, int x){
    if(n >= x){
        return max(0, x-1);
    }
    else{
        return max(0, x-1 - 2*(x-1-n));
    }
}

void solve(){
    int n, k;
    cin >> n >> k;

    ll ans = 0;
    for(int ab = 2; ab <= 2*n+5; ++ab){
        int cd = ab - k;
        ans += ways(n, ab)*ways(n, cd);
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}