/*
The maximum possible number of islands will form a checkerboard pattern.
The minimum number of changes needed to transform the grid into a
checkerboard pattern is the answer. In the case that there are an odd number
of squares, there is only one valid pattern (where the top-left corner is an
island). Otherwise, there are two, and the cheapest option as the answer.
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
    v2<char> g = fill(n, m, '?');
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> g[i][j];
        }
    }

    int ans = 1e9;
    for(int mod = 0; mod < 2; ++mod){
        int count = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if((i+j)%2==mod){
                    if(g[i][j]=='.'){
                        ++count;
                    }
                }
                else if(g[i][j]=='*'){
                    ++count;
                }   
            }
        }
        ans = min(ans, count);
        if((n*m)%2 == 1){
            break;
        }
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
