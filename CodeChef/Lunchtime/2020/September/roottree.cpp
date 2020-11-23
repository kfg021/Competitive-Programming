/*
In order for the reuslting graph to be a directed tree, there must be only
one node with an indgree of 0 (the root). Therefore, the answer will be
(# of nodes with indegree 0) - 1. 
The first part of the operation is satisfied because we will always be 
able to find an edge to remove. If there exists a node with indegree 0
in a tree, there will be at least one node with indegree >= 2.
We will remove an edge from this node.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }
#define F first
#define S second

void solve(){
    int n;
    cin >> n;
    vector<int> indeg(n, 0);
    for(int i = 0; i < n-1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        ++indeg[v];
    }

    int num0 = 0;
    for(int i = 0; i < n; ++i){
        if(indeg[i]==0) ++num0;
    }

    assert(num0!=0);
    cout << num0-1 << "\n";
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