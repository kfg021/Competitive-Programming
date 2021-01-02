/*
We can root the tree, and perform a bfs to find the distance of each node from
the root. Instead of calculating the answer directly, for each node, we can store
a value representing the amount we need to add to this node's subtree. We can use
this to solve each query in constant time. 

Let a and b be the two nodes in the query. If a is closer to the root than b, then
we add x to the root and subtract x from node b. Otherwise, we add x to node a.

At the end, we can do another bfs to propagate values down the tree.
*/

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
    int n;
    cin >> n;
    v2<int> adj(n);
    vector<ll> num(n, 0);
    vector<pair<int,int>> edges(n);
    for(int i = 0; i < n-1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[i] = {u, v};
    }

    queue<int> bfs;
    bfs.push(0);
    vector<int> d(n, -1);
    d[0] = 0;
    while(!bfs.empty()){
        int node = bfs.front();
        bfs.pop();
        for(int next : adj[node]){
            if(d[next]==-1){
                d[next] = 1+d[node];
                bfs.push(next);
            }
        }
    }

    int q;
    cin >> q;
    for(int i = 0; i < q; ++i){
        int t, e, x;
        cin >> t >> e >> x;
        --e;
        int a = edges[e].F;
        int b = edges[e].S;
        if(t==2){
            swap(a, b);
        }

        // reachable from a without b
        if(d[a] < d[b]){
            num[0] += x;
            num[b] -= x;
        }
        else{
            num[a] += x;
        }
    }

    bfs = queue<int>();
    bfs.push(0);
    vector<bool> v(n, false);
    v[0] = true;
    while(!bfs.empty()){
        int node = bfs.front();
        bfs.pop();
        for(int next : adj[node]){
            if(!v[next]){
                v[next] = true;
                num[next] += num[node];
                bfs.push(next);
            }
        }
    }

    for(int i = 0; i < n; ++i){
        cout << num[i] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}