/*
An important observation is that the operations on rows and columns are
independent (Swapping rows doesn't effect columns, and vice versa). So,
we can consider them seperately and multiply their results. 

First, lets figure out which rows/columns can be swapped with each other.
Because of small constraints, this can be done naively. We will create
two seperate adjacency lists, one for the rows and one for the columns.

For each connected component, we will have to multiply the answer by 
s!, where s is the size of this component. This is beacuse any permutation
within this component is achievable.

We can use dfs to calculate the components for both the row and column
graphs.
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }

const int MOD = 998244353;
inline int add(int a, int b){ return (a+b)%MOD; }
inline int sub(int a, int b){ return ((a-b)%MOD + MOD)%MOD; }
inline int mul(int a, int b){ return ((ll)a*b)%MOD; }

int n, k;
v2<int> adjc, adjr;
vector<int> v, fact;

int dfs(v2<int>& adj, int node){
    v[node] = true;
    int ans = 1;
    for(int i : adj[node]){
        if(!v[i])
            ans += dfs(adj, i);
    }
    return ans;
}

int ways(v2<int>& adj){
    int x = 1;
    v = vector<int>(n, false);
    for(int i = 0; i < n; ++i){
        if(!v[i]){
            int s = dfs(adj, i);
            x = mul(x, fact[s]);
        }
    }
    return x;
}

void solve(){
    cin >> n >> k;

    v2<int> m = fill(n,n,-1);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> m[i][j];
        }
    }

    adjc = v2<int>(n), adjr = v2<int>(n);
    for(int x = 0; x < n; ++x){
        for(int y = x+1; y < n; ++y){
            bool okc=true, okr=true;
            for(int i = 0; i < n; ++i){
                if(m[i][x]+m[i][y] > k){
                    okc = false;
                }
                if(m[x][i]+m[y][i] > k){
                    okr = false;
                }
            }
            if(okc){
                adjc[x].push_back(y);
                adjc[y].push_back(x);
            }
            if(okr){
                adjr[x].push_back(y);
                adjr[y].push_back(x);
            }
        }
    }

    fact = vector<int>(n+1);
    fact[0] = 1;
    for(int i = 1; i <= n; ++i){
        fact[i] = mul(i, fact[i-1]);
    }

    int r = ways(adjr);
    int c = ways(adjc);
    int ans = mul(r, c);
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}