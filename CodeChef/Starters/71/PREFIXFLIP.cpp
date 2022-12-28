#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){
    return v2<T>(r, vector<T>(c, t));
}
#define F first
#define S second

int n;
string s;
v2<int> dp;

int f(int end1, int end2){
    if(end1 < 0 || end2 >= n){
        return 0;
    }
    if(dp[end1][end2] != -1){
        return dp[end1][end2];
    }

    int ans = 0;
    if(s[end1] == s[end2]){
        ans = max(ans, 1+f(end1-1, end2+1));
    }
    ans = max(ans, f(end1-1, end2));
    ans = max(ans, f(end1, end2+1));
    
    dp[end1][end2] = ans;
    return ans;
}

void solve(){
    cin >> n;
    cin >> s;
    dp = fill(n, n, -1);

    int ans = 0;
    for(int i = 0; i+1 < n; i++){
        ans = max(ans, f(i, i+1));
    }
    cout << ans << "\n";
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
