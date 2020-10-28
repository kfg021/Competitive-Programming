/*
We can solve this problem with a greedy approach. We always want to maximize 
the number of nodes at the current depth so that we can we minimize the
number of nodes at higher depths. We can simulate the BFS, and consider
the children of the current node to be the longest increasing subarray
starting from the index of the current node.
*/

#include <bits/stdc++.h> 
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        --a[i];
    }

    vector<int> d(n, -1);
    queue<int> q;
    q.push(0);
    d[0] = 0;
    int i = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();

        int prev = -1;
        while(i<n && a[i]>prev){
            d[a[i]] = 1+d[u];
            q.push(a[i]);
            prev = a[i];
            ++i;
        }
    }

    int ans = *max_element(d.begin(), d.end());
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