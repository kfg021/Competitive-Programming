/*
We can use a Disjoint Set Union data structure to handle the queries of
type 1. For the queries of type 2, we make an addition to the normal
DSU by also storing the number of classes of each type that each group has.
During a merge, we combine the respective groups' class lists into one.
Since we merge class lists from small to large, these operations amortize
to O(n log n) complexity.
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }
#define F first
#define S second

struct DSU{
    vector<int> par, sz;
    int groups;

    vector<map<int,int>> classes;

    DSU(){}
    DSU(int n, vector<int>& c){
        par = sz = vector<int>(n);
        for(int i = 0; i < n; ++i){
            par[i] = i;
            sz[i] = 1;
        }
        groups = n;

        classes = vector<map<int,int>>(n);
        for(int i = 0; i < n; ++i){
            ++classes[i][c[i]];
        }
    }

    int find(int a){
        int root = a;
        while(root != par[root]){
            root = par[root];
        }

        while(a != root){
            int next = par[a];
            par[a] = root;
            a = next;
        }

        return root;
    }

    void merge(int a, int b){
        int root1 = find(a);
        int root2 = find(b);

        if(root1 != root2){
            if(sz[root1] > sz[root2]){
                swap(root1, root2);
            }

            sz[root2] += sz[root1];
            par[root1] = root2;

            for(auto& i : classes[root1]){
                classes[root2][i.F] += i.S;
            }
            classes[root1].clear();

            --groups;
        }
    }
};

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> c(n);
    for(int i = 0; i < n; ++i){
        cin >> c[i];
        --c[i];
    }
    
    DSU d(n, c);
    for(int i = 0; i < q; ++i){
        int t, a, b;
        cin >> t >> a >> b;
        --a, --b;
        if(t==1){
            d.merge(a, b);
        }
        else{
            int group = d.find(a);
            cout << d.classes[group][b] << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}