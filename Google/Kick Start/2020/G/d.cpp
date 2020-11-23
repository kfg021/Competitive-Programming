/*
Only passes the first test set of this problem, where n <= 9.

I wrote a brute force to generate all possible ending sums, and
divided their sum by the total number of elements to find the
answer.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

vector<ll> f(vector<ll>& x, ll score){
    int l = x.size();
    if(l==1){
        return {score};
    }

    vector<ll> ans = {};
    for(int i = 0; i < l-1; ++i){
        vector<ll> next;
        for(int j = 0; j < l; ++j){
            if(j!=i && j!=i+1){
                next.push_back(x[j]);
            }
            else if(j==i){
                next.push_back(x[i]+x[i+1]);
            }
        }

        for(ll j : f(next, score+x[i]+x[i+1])){
            ans.push_back(j);
        }
    }

    return ans;
}

void solve(){
    int n;
    cin >> n;

    vector<ll> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];


    vector<ll> all = f(a, 0);
    ll sum = 0;
    for(ll i : all){
        sum += i; 
    }
    int l = all.size();

    ld ans = (ld)sum/l;
    cout << fixed << setprecision(9) << ans << "\n";
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