/*
If k <= (n-1 choose 2), a valid graph exists by construction. 
We can start with a star graph of size n (n-1 vertices of degree n and one
of degree 1). The diameter of this graph will be 2. For every edge we add
between two non-center nodes, we will reduce the number of pairs with a
distance 2 by 1. We will add (n-1 choose 2) - k of these edges to obtain
a score of k.

If k = (n choose 2), a valid graph also exists. We can build a complete graph
of size n.

Otherwise, if (n-1 choose 2) < k < (n-1 choose 2), no valid graph exists.
A graph with n nodes and diameter 1 must be complete and would give us a
score of (n choose 2). Any graph with diameter > 1 will have a maximum
score <= (n-1 choose 2).
*/

#include <bits/stdc++.h>
using namespace std;

int nc2(int n){
    return (n*(n-1)) / 2;
}

void solve(){
    int n, k;
    cin >> n >> k;

    if(k <= nc2(n-1)){
        int diff = nc2(n-1) - k;
        cout << n-1 + diff << "\n";
        for(int i = 2; i <= n; ++i){
            cout << "1 " << i << "\n";
        }
        for(int i = 2; i <= n && diff > 0; ++i){
            for(int j = i+1; j <= n && diff > 0; ++j, --diff){
                cout << i << " " << j << "\n";
            }
        }
    }
    else if(k == nc2(n)){
        cout << nc2(n) << "\n";
        for(int i = 1; i <= n; ++i){
            for(int j = i+1; j <= n; ++j){
                cout << i << " " << j << "\n";
            }
        }
    }
    else{
        cout << "-1\n";
    }
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
