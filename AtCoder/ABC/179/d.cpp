/*
We will solve this problem with a dp, where our state is
dp[i] = # of ways to reach cell i. Our answer will be dp[n-1].
Lets save a prefix sum for the dp as we go. For each range [l, r], we can
add sum of the range [dp[i-r], dp[i-1]] to dp[i] in O(1). Since there are
k ranges, the transition will be O(k).
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
#define F first
#define S second

const int MOD = 998244353;
inline int add(int a, int b){ return (a+b)%MOD; }
inline int sub(int a, int b){ return ((a-b)%MOD + MOD)%MOD; }
inline int mul(int a, int b){ return ((ll)a*b)%MOD; }

void solve(){
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(k);
    for(int i = 0; i < k; ++i){
        cin >> a[i].F >> a[i].S;
    }

    vector<int> dp(n, -1);
    vector<int> pref(n, -1);

    dp[0] = 1;
    pref[0] = 1;

    for(int i = 1; i < n; ++i){
        dp[i] = 0;
        for(int j = 0; j < k; ++j){
            int p1 = i-a[j].F >= 0 ? pref[i-a[j].F] : 0;
            int p2 = i-a[j].S-1 >= 0 ? pref[i-a[j].S-1] : 0;
            int toAdd = sub(p1, p2);
            dp[i] = add(dp[i], toAdd);
        }

        pref[i] = add(pref[i-1], dp[i]);
    }

    cout << dp[n-1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}