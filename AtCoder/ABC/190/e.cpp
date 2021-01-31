/*
First, make a graph connecting the gems that are allowed to be adjacent.
A valid ordering is a path in this graph.
We would like to use the fact that k is small (k <= 17). We can make a new
graph where each gem in the c array is connected to each other gem in c, and
the weight of this connection is the distance between the two gems in the
original array. We can construct this new graph in O(nk) time using BFS.
This new graph will have O(k) vertices and O(k^2) edges.

The answer will be the minimum distance in this graph touching each vertex once.
In fact, this is equivalent to the Travelling Salesman Problem. We can solve it
with a dp, where dp[node][mask] = the minimum distance we need to get all gems
when we start at node and mask is a bitmask representing all gems we have already
seen (0 <= mask < 2^k).

The answer will be 1 + min(i=0, k-1) dp[i][0]
(The problem wants the total number of gems, not the distance).

*/

#include <bits/stdc++.h> 
using namespace std;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){
    return v2<T>(r, vector<T>(c, t));
}

const int INF = 1e9;

int n, m, k;
v2<int> adj, dist;
vector<int> c;

// min distance we need to travel to get all gems starting at node having seen gems in mask
v2<int> dp;
int f(int node, int mask){
    if(mask == (1<<k) - 1){
        return 0;
    }
    if(dp[node][mask] != -1){
        return dp[node][mask];
    }

    dp[node][mask] = INF;
    for(int next = 0; next < k; ++next){
        if((mask>>next) & 1 || dist[node][next] == -1) continue;
        dp[node][mask] = min(dp[node][mask], dist[node][next] + f(next, mask | (1<<next)));
    }
    return dp[node][mask];
}

void solve(){
    cin >> n >> m;
    adj = v2<int>(n);
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> k;
    c = vector<int>(k);
    for(int i = 0; i < k; ++i){
        cin >> c[i];
        --c[i];
    }

    v2<int> dist_large = fill(k, n, -1);
    for(int i = 0; i < k; ++i){
        queue<int> q;
        q.push(c[i]);
        dist_large[i][c[i]] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int next : adj[node]){
                if(dist_large[i][next] == -1){
                    dist_large[i][next] = 1 + dist_large[i][node];
                    q.push(next);
                }
            }
        }
    }
    
    dist = fill(k, k, -1);
    for(int i = 0; i < k; ++i){
        for(int j = 0; j < k; ++j){
            dist[i][j] = dist_large[i][c[j]];
        }
    }

    dp = fill(k, 1<<k, -1);
    int ans = INF;
    for(int i = 0; i < k; ++i){
        ans = min(ans, f(i, 0));
    }
    if(ans == INF){
        cout << "-1\n";
    }
    else{
        cout << ans+1 << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}