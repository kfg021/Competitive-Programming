/*
If we ever have (u, v) = (v, u), then the answer is YES. This is because
we can go back and forth between u and v giving us the palindromes
aaa... or bbb... .

Otherwise, (u, v) != (v, u) for all u, v. If m is odd, then the answer is also
YES, since we can alternate between any two nodes giving us aba...a or bab...b.

The only case left is where m is even. 
If n = 2, it can be easily shown that there is no solution.

For n > 2, it is always possible.
Since the graph is complete and from the earlier assumptions, it can be shown
that there always exists three nodes u, v, w such that (u, v) = (v, w).

Given this, we can create even palindromes of the form 
aba...bb...aba (if m is a multiple of 4) and ab...aa...ba (otherwise).
*/

#include <bits/stdc++.h> 
using namespace std;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){
    return v2<T>(r, vector<T>(c, t));
}


void solve(){
    int n, m;
    cin >> n >> m;
    v2<char> g = fill(n, n, '?');
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> g[i][j];
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            if(g[i][j] == g[j][i]){
                cout << "YES\n";
                for(int k = 0; k <= m; ++k){
                    if(k%2==0) cout << i+1 << " ";
                    else cout << j+1 << " ";
                }
                cout << "\n";
                return;
            }
        }
    }

    if(m%2==1){
        cout << "YES\n";
        for(int k = 0; k <= m; ++k){
            if(k%2==0) cout << "1 ";
            else cout << "2 ";
        }
        cout << "\n";
        return;
    }

    if(n==2){
        cout << "NO\n";
        return;
    }

    vector<int> v = {0, 1, 2};
    do{
        if(g[v[0]][v[1]] == g[v[1]][v[2]]){
            cout << "YES\n";
            for(int i = 0; i <= m; ++i){
                int mod = (m/2+i)%2;
                if(mod==0) cout << v[1]+1 << " ";
                else{
                    if(i < m/2) cout << v[0]+1 << " ";
                    else cout << v[2]+1 << " ";
                }
            }
            cout << "\n";
            return;
        }
    }
    while(next_permutation(v.begin(), v.end()));

    assert(false);
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