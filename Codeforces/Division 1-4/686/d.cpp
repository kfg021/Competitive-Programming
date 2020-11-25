/*
The maximum k will be the greatest power among prime factors of n. If k
were any greater, it would be impossible to satisfy the divisibility
constraint in the problem.
A valid construction for a is as follows:
    a_i = {p if 1 <= i <= k-1, n / p^(k-1) if i = k}
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
#define F first
#define S second

void solve(){
    ll n;
    cin >> n;

    map<ll,int> primes;
    ll t = n;
    for(ll i = 2; i*i <= t; ++i){
        while(t%i==0){
            t/=i;
            ++primes[i];
        }
    }
    if(t>1){
        ++primes[t];
    }

    ll best = -1;
    for(auto i : primes){
        if(best==-1 || i.S > primes[best]){
            best = i.F;
        }
    }

    int k = primes[best];
    cout << k << "\n";
    ll pow = 1;
    for(int i = 0; i < k-1; ++i){
        cout << best << " ";
        pow *= best;
    }
    cout << n/pow << "\n";
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