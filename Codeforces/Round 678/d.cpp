/*
Essentially, this problem boils down to minimizing the maximum across
all leaves. This implies that we should split the citizens amongst the 
leaves as evenly as possible.

Consider a struct that contains the following infomation:
    max - the maximum leaf in this subtree
    num - the number of leaves in this subtree
    aval - the maximum number of citizens we could add to this subtree such
    that the max leaf will remain constant

Consider a recursive function f that returns an instance of this struct. Our
base case is f(leaf_node) = {a[leaf_node], 1, 0}. We can construct the answer
for an arbitrary node by combining the answers of its children. The logic for
combining two child answers is implemented in the "merge" function. We will
also need to split the citizens in this node between leaves such that the
maximum leaf is minimized. We will first exaust the aval value, leaving the
max unchanged. Then, we split the remaining citizens evenly across the leaves
in this node's subtree.

The final answer will be f(root_node).max .
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }

v2<int> adj;
vector<int> a;

struct state{
    ll max, num, aval;
};

state merge(state l, state r){
    if(l.max > r.max){
        swap(l, r);
    }

    state ans = l;
    ans.max = r.max;
    ans.aval += (r.max-l.max)*l.num + r.aval;
    ans.num += r.num;

    return ans;
}

state dfs(int node){
    if(adj[node].empty()){
        return {a[node], 1, 0};
    }

    state ans = {0, 0, 0};
    for(int next : adj[node]){
        ans = merge(ans, dfs(next));
    }

    if(a[node] <= ans.aval){
        ans.aval -= a[node];
    }
    else{
        ll left = a[node]-ans.aval;
        ans.aval = 0;

        ll split = left/ans.num;
        ans.max += split;
        ll mod = left%ans.num;
        if(mod>0){
            ++ans.max;
            ans.aval = ans.num-mod;
        }
    }

    return ans;
}

void solve(){
    int n;
    cin >> n;
    adj = v2<int>(n);
    for(int i = 1; i < n; ++i){
        int p;
        cin >> p;
        --p;
        adj[p].push_back(i);
    }
    a = vector<int>(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    state ans = dfs(0);
    cout << ans.max << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}