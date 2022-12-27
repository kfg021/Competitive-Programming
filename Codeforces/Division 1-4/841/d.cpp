#include <bits/stdc++.h>
using namespace std;
using v2 = vector<vector<int>>;

int largest(v2& a, int k){
    int n = a.size();
    int m = a[0].size();
    v2 dp(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        dp[i][0] = a[i][0] >= k ? 1 : 0;
    }
    for(int j = 0; j < m; j++){
        dp[0][j] = a[0][j] >= k ? 1 : 0;
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(a[i][j] >= k) dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}

void solve(){
    int n, m;
    cin >> n >> m;
    v2 a(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    int lo = 1;
    int hi = min(n, m);
    int ans = -1;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(largest(a, mid) >= mid){
            ans = mid;
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    assert(ans != -1);
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