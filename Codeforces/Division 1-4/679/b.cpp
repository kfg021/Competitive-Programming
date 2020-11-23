/*
We are given a list of rows, and we can use this information to determine
the correct column for each element. Similarly, we are given a list of
columns, and we can use this to determine the correct row for each element.
Since we now know the row and column of every element, we can construct the
full matrix.
*/

#include <bits/stdc++.h> 
using namespace std;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }

void solve(){
    int n, m;
    cin >> n >> m;
    v2<int> rows = fill(n, m, -1);
    v2<int> cols = fill(m, n, -1);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> rows[i][j];
            --rows[i][j];
        }
    }
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cin >> cols[i][j];
            --cols[i][j];
        }
    }

    map<int, int> row, col;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            col[rows[i][j]] = j;
        }
    }
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            row[cols[i][j]] = j;
        }
    }

    v2<int> ans = fill(n, m, -1);
    for(int i = 0; i < n*m; ++i){
        ans[row[i]][col[i]] = i;
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cout << ans[i][j]+1 << " ";
        }
        cout << "\n";
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