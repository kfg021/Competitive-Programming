/*
If there is any point where the sum of active water use is greater than
w, the answer is No. Otherwise the answer is Yes. We need an efficient way
to determine the total water usage at every point of time.

We can do this in constant time per interval by initializing a prefix array
A with zeros. If person uses x units of water from times [a, b], we add x
to A[a] and subtract x from A[b+1]. 
After all modifications, we construct the true array from the prefix array.

Another possible solution is to use a segment tree with lazy propagation to
handle the range updates, but this is overkill and introduces an
unnecessary log factor to the time complexity.
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

void solve(){
    int n, w;
    cin >> n >> w;
    vector<int> s(n), t(n), p(n);
    for(int i = 0; i < n; ++i){
       cin >> s[i] >> t[i] >> p[i];
    }

    const int T = 2e5+5;
    vector<ll> amt(T, 0);
    for(int i = 0; i < n; ++i){
        amt[s[i]] += p[i];
        amt[t[i]] -= p[i];
    }
    for(int i = 1; i < T; ++i){
        amt[i] += amt[i-1];
    }
    for(int i = 0; i < T; ++i){
        if(amt[i] > w){
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}