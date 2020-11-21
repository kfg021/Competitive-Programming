/*
We can solve this problem for any tree, so the answer is YES (simply consider
any n-1 edges). Preform a DFS starting from the root. For each edge connected
to the current node, check whether the current node's value (already set by
parent) matches the value of this edge. If they dont match, set the other node
connected to this edge to the value of the edge. If they do match, set it to
some other value. Recursively call this function on children.
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }
#define F first
#define S second

int n, m;
v2<pair<int,int>> adj;

vector<bool> v;
vector<int> ans;
void dfs(int node){
    v[node] = true;
    for(pair<int,int> edge : adj[node]){
        int next = edge.F, w = edge.S;
        if(!v[next]){
            assert(ans[node] != -1);
            if(ans[node] != w){
                ans[next] = w;
            }
            else{
                ans[next] = (w+1)%n;
            }
            dfs(next);
        }
    }
}

void solve(){
    cin >> n >> m;
    adj = v2<pair<int,int>>(n);
    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v, --w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    ans = vector<int>(n, -1);
    ans[0] = 0;
    v = vector<bool>(n, false);
    dfs(0);

    for(int i = 0; i < n; ++i){
        cout << ans[i]+1 << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}