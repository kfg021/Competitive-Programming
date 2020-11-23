/*
Consider a dynamic programming approach where our state is dp[i][j] =
the number of ways to arrive at square (i, j). Calculating the transition
by considering every square the queen could have come from will be be O(n),
creating a total time complexity of O(n^3), which is too slow.
We can improve this be storing prefix sums for the horizontal, vertical,
and diagonal directions. If we reach a wall square, we reset these prefix
sums to 0. We can find the value for the current dp state from the prefix
arrays, and update said arrays, in constant time.

The answer will be dp[h-1][w-1].
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }

const int MOD = 1e9+7;

void solve(){
    int h, w;
    cin >> h >> w;
    v2<char> grid = fill(h, w, '?');
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            cin >> grid[i][j];
        }
    }

    v2<int> dp = fill(h, w, 0), horiz, vert, diag;
    horiz = vert = diag = dp;
    
    dp[0][0] = horiz[0][0] = vert[0][0] = diag[0][0] = 1;
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            if(!i&&!j) continue;
            if(grid[i][j] == '#') continue;

            int h = (j-1>=0) ? horiz[i][j-1] : 0;
            int v = (i-1>=0) ? vert[i-1][j] : 0;
            int d = (i-1>=0 && j-1>=0) ? diag[i-1][j-1] : 0;

            dp[i][j] = ((ll)h+v+d)%MOD;
            horiz[i][j] = (dp[i][j] + h)%MOD;
            vert[i][j] = (dp[i][j] + v)%MOD;
            diag[i][j] = (dp[i][j] + d)%MOD;
        }
    }

    cout << dp[h-1][w-1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}