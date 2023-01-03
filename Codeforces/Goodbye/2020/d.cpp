/*
It is optimal for each color to have one connected component, so that 
each vertex contributes to the sum.

As we increase k, we will be able to increase the score by moving edges
to other groups (while making sure that each color only has one component). 
Each vertex i will contribute w[i] * e[i], where e[i] is the number of different
colors among edges connected to i.

We can use a priority queue to repeatedly take the highest weight vertex with
remaining degree > 1.
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
#define F first
#define S second

void solve(){
    int n;
    cin >> n;
    vector<int> w(n);
    vector<int> deg(n, 0);
    for(int i = 0; i < n; ++i){
        cin >> w[i];
    }
    for(int i = 0; i < n-1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;

        ++deg[u], ++deg[v];
    }

    priority_queue<pair<int,int>> pq;
    for(int i = 0; i < n; ++i){
        pq.push({w[i], deg[i]});
    }

    ll ans = 0;
    for(int i : w) ans += i;
    cout << ans << " ";

    for(int i = 2; i <= n-1; ++i){
        while(pq.top().S <= 1){
            assert(!pq.empty());
            pq.pop();
        }
        assert(!pq.empty());

        int weight = pq.top().F;
        int degree = pq.top().S;
        pq.pop();

        ans += weight;
        cout << ans << " ";

        pq.push({weight, degree-1});
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