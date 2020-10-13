/*
I didn't actually manage to solve this one during the contest. The basic
idea is to do a dp with some optimizations. 
Our state is dp[i] = the max number of celebrities we can get assuming we take celebrity i. 
In the normal case this would be O(n^2). However, for each node, we only 
need to check the 2r most recent nodes. This is because the largest possible 
manhattan distance between two nodes is 2r. Any celebrity more with a
greater time differential than this can certianly be reached. We can consider 
them all at once by using an array mx, where mx[i] = max(dp[0], ... ,dp[i]).
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }
#define F first
#define S second

void solve(){ 
    int r, n;
    cin >> r >> n;
    vector<int> t(n+1), x(n+1), y(n+1);
    t[0] = 0;
    x[0] = 1;
    y[0] = 1;
    for(int i = 1; i <= n; ++i){
        cin >> t[i] >> x[i] >> y[i];
    }

    const int INF = 1e9;

    vector<int> dp(n+1, -INF), mx(n+1, -INF);

    dp[0] = 0;
    mx[0] = 0;
    for(int i = 1; i <= n; ++i){
        if(i-2*r-1 >= 0){
            dp[i] = 1+mx[i-2*r-1];
        }
        for(int j = i-2*r; j < i; ++j){
            if(j<0) continue;
            if((abs(x[i]-x[j]) + abs(y[i]-y[j])) <= t[i]-t[j]){
                dp[i] = max(dp[i], 1+dp[j]);
            }
        }

        mx[i] = max(mx[i-1], dp[i]);
    }

    int ans = 0;
    for(int i = 0; i <= n; ++i){
        ans = max(ans, dp[i]);
    }
    if(ans<0){
        cout << "0\n";
    }
    else{
        cout << ans << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}