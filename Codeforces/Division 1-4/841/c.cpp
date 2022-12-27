#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    long long bad = 0;
    int x = 0;
    vector<int> s(4*n+10, 0);
    s[0] = 1;
    for(int i = 0; i < n; i++){
        x ^= a[i];
        for(int j = 0; j*j <= 2*n; j++){
            int k = x ^ (j*j);
            bad += s[k];
        }
        s[x]++;
    }

    ll ans = ((ll)n*(n+1))/2 - bad;
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for(int i = 0; i < t; ++i){
        solve();
    }
    return 0;
}