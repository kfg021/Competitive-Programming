/*
Consider every connected component of the graph seperately. For each 
component, the answer is determined by the sum all a values in this component. 
If this is not equal to the sum of all b values in this component, then the
answer is No. This is because the operations in this problem leave the total
sum unchanged. Otherwise, this component works. To see why this is true,
consider an algorithm where we first set the leaves and work our way inwards. 

If every component works, the answer will be Yes. If at least one component
fails, the answer is No.
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }

v2<int> adj;
vector<int> v;
vector<int> nodes;
void dfs(int node){
    v[node] = true;
    nodes.push_back(node);
    for(int next : adj[node]){
        if(!v[next]){
            dfs(next);
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;

    adj = v2<int>(n);
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];
    for(int i = 0; i < m; ++i){
        int c, d;
        cin >> c >> d;
        --c, --d;
        adj[c].push_back(d);
        adj[d].push_back(c);
    }

    v = vector<int>(n, false);

    for(int i = 0; i < n; ++i){
        if(!v[i]){
            nodes.clear();
            dfs(i);
            ll sa=0, sb=0;
            for(int node : nodes){
                sa += a[node];
                sb += b[node];
            }
            if(sa!=sb){
                cout << "No\n";
                return;
            }
        }
    }

    cout << "Yes\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}