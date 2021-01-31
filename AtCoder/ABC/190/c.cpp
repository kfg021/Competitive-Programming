#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){
    return v2<T>(r, vector<T>(c, t));
}
#define F first
#define S second

void solve(){
    int n, m, k;
    cin >> n >> m;
    vector<pair<int,int>> a(m);
    for(int i = 0; i < m; ++i){
        cin >> a[i].F >> a[i].S;
        --a[i].F, --a[i].S;
    }
    cin >> k;
    vector<pair<int,int>> c(k);
    for(int i = 0; i < k; ++i){
        cin >> c[i].F >> c[i].S;
        --c[i].F, --c[i].S;
    }

    int ans = 0;
    for(int mask = 0; mask < (1<<k); ++mask){
        vector<bool> seen(m, false);
        for(int i = 0; i < k; ++i){
            if((mask >> i) & 1){
                seen[c[i].F] = true;
            }
            else{
                seen[c[i].S] = true;
            }
        }

        int count = 0;
        for(int i = 0; i < m; ++i){
            if(seen[a[i].F] && seen[a[i].S]){
                ++count;
            }
        }
        ans = max(ans, count);
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}