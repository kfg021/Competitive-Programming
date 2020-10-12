/*
We can split the matrix into groups based on which numbers need to be the same
(For example, a[i][j] would need to be in the same group as a[i][m-1-j]).
We can solve for each group seperatley, and take the sum over all groups. 
For each group, we need to find the number x such that sum(k=0, len(g)-1)(abs(x-g[k]))
is minimized. This is a classic problem, and it turns out the median
is the optimal answer.
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }
#define F first
#define S second

using P = pair<int, int>;

map<P, vector<P>> adj;
v2<int> a;

set<P> v;
vector<int> dfs(P node){
    v.insert(node);
    vector<int> ans = {a[node.F][node.S]};
    for(P& p : adj[node]){
        if(!v.count(p)){
            vector<int> next = dfs(p);
            for(int i : next){
                ans.push_back(i);
            }
        }
    }
    return ans;
}

void solve(){
    int n, m;
    cin >> n >> m;
    a = fill(n, m, -1);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> a[i][j];
        }
    }

    adj.clear();
    v.clear();

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            adj[{i, j}].push_back({n-1-i, j});
            adj[{i, j}].push_back({i, m-1-j});
        }
    }

    ll ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(v.count({i, j})) continue;
            vector<int> all = dfs({i, j});
            int l = all.size();

            sort(all.begin(), all.end());

            int median = all[l/2];
            ll add = 0;
            for(int i : all){
                add += abs(median-i);
            }
            ans += add;
        }
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