/*
We are given a graph with n nodes and n edges, so it is almost a tree.
In fact, we can treat it as a circular graph, were each vertex is the
root of a tree. Now, we can split the paths into two categories: internal
paths (paths that remain within single tree) and external paths (paths
that travel along the cycle and touch two trees). 


For the internal paths, we can consider each tree seperately. For each node
of the tree, we consider the paths ending at node i and the paths passing
through node i (travelling up to node i and back down). 

The number of paths ending at node i can be expressed as:
    ending_i = sum(j)(size_of_subtree_j)
The number of paths passing through node i can be expressed as:
    passing_i = 1/2 ( (sum(j)(size_of_subtree_j)) ^ 2 - sum(j)(size_of_subtree_j ^ 2) )
(for each subtree j of node i)

The total number of paths containing node i is therefore:
    total_i = ending_i + passing_i


For the external paths, we need to consider paths that are part of two trees.
The number of external paths passing through the tree rooted at node i (where
nodes i, j are of the cycle) can be expressed as 
    external_i = ending_i * (sum(j)(ending_j) - ending_i)


The answer will be:
    sum(i)(internal_i) + sum(j)(external_j)
For all nodes i and for all nodes j on the cycle.
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

v2<int> adj, ss;
vector<int> root;

vector<int> genpath(vector<int>& p, int start){
    vector<int> path;
    int cur = start;
    while(cur != -1){
        path.push_back(cur);
        cur = p[cur];
    }
    reverse(path.begin(), path.end());
    return path;
}

vector<int> getcycle(v2<int>& adj){
    int n = adj.size();
    queue<int> q;
    q.push(0);
    vector<int> v(n, 0), p(n, -1);
    v[0] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        v[node] = 2;
        for(int next : adj[node]){
            if(v[next] == 1){
                vector<int> nodepath = genpath(p, node);
                vector<int> nextpath = genpath(p, next);
                int l1 = nodepath.size(), l2 = nextpath.size();
                int start = 0;
                while(start+1 < min(l1, l2) && nodepath[start+1] == nextpath[start+1]){
                    ++start;
                }

                vector<int> cycle;
                for(int i = start; i < l1; ++i){
                    cycle.push_back(nodepath[i]);
                }
                for(int i = l2-1; i > start; --i){
                    cycle.push_back(nextpath[i]);
                }
                return cycle;
            }
            else if(v[next] == 0){
                v[next] = 1;
                p[next] = node;
                q.push(next);
            }

        }
    }
    assert(false);
}

void setss(int node, int start, vector<pair<int,int>>& removed){
    root[node] = start;
    for(int next : adj[node]){
        if(find(removed.begin(), removed.end(), pair<int,int>{node,next}) == removed.end()){
            if(root[next]==-1){
                setss(next, start, removed);
                int tot = 0;
                for(int i : ss[next]){
                    tot += i;
                }
                ss[node].push_back(1+tot);
            }
        }
    }
}

ll crosspaths(vector<int>& subtrees){
    ll sum = 0;
    ll sumsq = 0;
    for(int i : subtrees){
        sum += i;
        sumsq += (ll)i*i;
    }
    return (sum*sum - sumsq)/2;
}

void solve(){
    int n;
    cin >> n;
    adj = v2<int>(n);
    for(int i = 0; i < n; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> cycle = getcycle(adj);
    int l = cycle.size();
    assert(l>=3);

    ll ans = 0;

    ss = v2<int>(n);
    root = vector<int>(n, -1);
    map<int,ll> trees;

    for(int i = 0; i < l; ++i){
        int bef = cycle[(i+l-1)%l];
        int cur = cycle[i];
        int aft = cycle[(i+1)%l];
        vector<pair<int,int>> removed = {{bef, cur}, {cur, bef}, {cur, aft}, {aft, cur}};
        setss(cur, cur, removed);
        trees[cur] = 1;
        for(int sub : ss[cur]){
            trees[cur] += sub;
        }
    }

    for(int i = 0; i < n; ++i){
        for(int sub : ss[i]){
            ans += sub;
        }
        ans += crosspaths(ss[i]);
    }

    ll sumtree = 0;
    for(auto i : trees){
        sumtree += i.S;
    }

    for(auto i : trees){
        ans += i.S*(sumtree-i.S);
    }

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