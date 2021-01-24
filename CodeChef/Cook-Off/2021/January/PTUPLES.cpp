/*
The important observation is that every tuple must contain a 2 because it is
the only even prime. We can use the Sieve of Eratosthenes to precacluate
the answer for all testcases.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mx = 2e6;
vector<int> ans;

void sieve(){
    vector<bool> prime(mx+1, true);
    prime[0] = prime[1] = false;
    for(int i = 2; (ll)i*i <= mx; ++i){
        if(prime[i]){
            for(int j = i*i; j <= mx; j += i){
                prime[j] = false;
            }
        }
    }

    ans = vector<int>(mx+1);
    ans[0] = ans[1] = 0;
    for(int i = 2; i <= mx; ++i){
        ans[i] = ans[i-1];
        if(prime[i] && prime[i-2]){
            ++ans[i];
        }
    }
}

void solve(){
    int n;
    cin >> n;
    cout << ans[n] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int T; cin >> T;
    for(int i = 0; i < T; ++i){
        solve();
    }
    return 0;
}
