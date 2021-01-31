/*
Fix the total number of integers in the arethmetic sequence. Call this
value a. Let x be the minimum number in this sqeuence. It then holds that
x + (x+1) + (x+2) + ... + (x+a-1) = n

We can simplify this as
ax + a(a-1)/2 = n

Rearranging to get
2n = a(2x + a - 1)

So it holds that a is a factor of 2n.
We can check all factors of 2n in O(sqrt(n)) time.

To represent a valid arethmetic sequence it must hold that
2x = 2n/a - a + 1
In other words, 2n/a - a + 1 must be even.
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

vector<ll> factor(ll x){
    vector<ll> f;
    for(ll i = 1; i*i <= x; ++i){
        if(x%i == 0){
            f.push_back(i);
            if(i != x/i){
                f.push_back(x/i);
            }
        }
    }
    return f;
}

void solve(){
    ll n;
    cin >> n;

    vector<ll> f = factor(2*n);
    int ans = 0;
    for(ll a : f){
        ll _2x = (2*n)/a - a + 1;
        if(_2x % 2 == 0){
            ++ans;
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}