/*
Assume that the tree is rooted at index 0. It turns out it is enough to
assign 1's to nodes with even degree, and 0's to nodes with odd degree. 
To accomplish this, we will preform a bfs starting from the root.
*/

#include <bits/stdc++.h>
using namespace std;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }

void solve(){
    int n;
    cin >> n;

    v2<int> adj(n);
    for(int i = 0; i < n-1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    q.push(0);
    vector<int> num(n, -1);
    num[0] = 0;
    vector<bool> v(n, false);
    v[0] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int next : adj[node]){
            if(!v[next]){
                v[next] = true;
                num[next] = !num[node];
                q.push(next);
            }
        }
    }

    for(int i : num){
        cout << i+1 << " ";
    }
    cout << "\n";
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
