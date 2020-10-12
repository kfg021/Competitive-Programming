/*
I solved this problem after the contest ended.
A naive solution would be to create a weighted graph with edges 
connecting all pairs of vertices, and run Dijkstra's on the graph
to get our answer. Sadly, creating such a graph would be O(m^2), which
is too slow. The key insight is that we don't need to connect all pairs.
In fact, we only need to connect instant-movement locations that are
adjacent in either x or y coordinate. Obviously, we also need to connect
the start to all instant-movement spots, all instant-movement spots to
the end, and the start to the end. This is not an issue though because
it is only a linear amount of extra connections.
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }
#define F first
#define S second

using P = pair<int, int>;

int manh(P& a, P& b){
    return abs(a.F-b.F) + abs(a.S-b.S);
}

int tele(P& a, P& b){
    return min(abs(a.F-b.F), abs(a.S-b.S));
}

bool ysort(P& l, P&r){
    return make_pair(l.S, l.F) < make_pair(r.S, r.F);
}

void solve(){
    int n, m;
    cin >> n >> m;

    P start, end;
    cin >> start.F >> start.S >> end.F >> end.S;

    map<P, vector<pair<P, ll>>> adj;

    vector<P> v(m);
    for(int i = 0; i < m; ++i){
        cin >> v[i].F >> v[i].S;
    }

    sort(v.begin(), v.end());
    for(int i = 0; i < m-1; ++i){
        int dist = tele(v[i], v[i+1]);
        adj[v[i]].push_back({v[i+1], dist});
        adj[v[i+1]].push_back({v[i], dist});
    }

    sort(v.begin(), v.end(), ysort);
    for(int i = 0; i < m-1; ++i){
        int dist = tele(v[i], v[i+1]);
        adj[v[i]].push_back({v[i+1], dist});
        adj[v[i+1]].push_back({v[i], dist});
    }

    for(int i = 0; i < m; ++i){
        int dist1 = tele(start, v[i]);
        adj[start].push_back({v[i], dist1});

        int dist2 = manh(v[i], end);
        adj[v[i]].push_back({end, dist2});
    }

    adj[start].push_back({end, manh(start, end)});

    map<P, ll> d;
    priority_queue<pair<ll, P>, vector<pair<ll, P>>, greater<pair<ll, P>>> pq;
    pq.push({0, start});
    
    for(int i = 0; i < m; ++i){
        d[v[i]] = 1e18;
    }
    d[end] = 1e18;
    d[start] = 0;

    while(!pq.empty()){
        pair<ll, P> top = pq.top();
        P node = top.S;
        pq.pop();

        for(pair<P, ll>& edge : adj[node]){
            P& next = edge.F;
            ll weight = edge.S;
            if(d[node] + weight < d[next]){
                d[next] = d[node] + weight;
                pq.push({d[next], next});
            }
        }
    }

    cout << d[end] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}