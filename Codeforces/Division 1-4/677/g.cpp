/*
Lets first consider a matrix D, where D[i][j] represents the shortest
distance from node i to node j. We can compute D using Dijkstra's algorithm.
Next, consider every possible edge. Let (a, b) represent the nodes along this
edge. For each pair of verticies (c, d) in routes, we will consider two paths:
the direct path and the best path through edge (a, b), assuming it costs 0.
The former will simply be D[c][d]. The latter will be 
min(D[c][a] + D[b][d], D[c][b] + D[a][d]). Take the minimum of these two paths,
and sum over all routes. The answer will be the minimum of these sums.
*/

#include <bits/stdc++.h> 
using namespace std;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }
#define F first
#define S second

const int INF = 1e9;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> edges(m);
    v2<pair<int, int>> adj(n);
    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edges[i] = {u, v};
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<pair<int, int>> routes(k);
    for(int i = 0; i < k; ++i){
        cin >> routes[i].F >> routes[i].S;
        --routes[i].F, --routes[i].S;
    }

    v2<int> d = fill(n, n, INF);
    for(int i = 0; i < n; ++i){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, i});
        d[i][i] = 0;
        while(!pq.empty()){
            int u = pq.top().S;
            pq.pop();
            for(pair<int, int>& edge : adj[u]){
                int v = edge.F, w = edge.S;
                int newdist = d[i][u] + w;
                if(newdist < d[i][v]){
                    d[i][v] = newdist;
                    pq.push({newdist, v});
                }
            }
        }
    }

    int ans = INF;
    for(pair<int, int>& e : edges){
        int score = 0;
        for(pair<int, int>& r: routes){     
            int mindist = d[r.F][r.S];
            int thru = min(d[r.F][e.F]+d[e.S][r.S], d[r.F][e.S]+d[e.F][r.S]);
            score += min(mindist, thru);
        }
        ans = min(ans, score);
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}