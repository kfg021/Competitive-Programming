/*
Let N, M represent the dimensions of the matrix.

We can solve this problem with dynamic programming.
First, consider a dp where our state is dp1[r][c][m][n] = the maximum answer
for row r, using columns 0-c, congruent to m mod k, and using n numbers.
The best answers for each row will be dp2[r][M-1][m][n].

We can construct the final answer with another dp, where our state is 
dp2[r][m] = the maximum answer using rows 0-r and congruent to m mod k.

Our final answer will be dp2[N-1][0].

I prefer to calculate dp tables recursively, but it can be done iterativley
as well.
*/

#include <bits/stdc++.h> 
using namespace std;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }

const int INF = 1e9;

int sub(int a, int b, int mod){
    return (((a-b)%mod)+mod)%mod;
}

int n, m, k;
v2<int> g;

v2<v2<int>> dp1;
int f1(int r, int c, int mod, int num){
    if(num==0){
        if(mod==0){
            return 0;
        }
        else{
            return -INF;
        }
    }
    if(c==-1){
        if(mod==0 && num==0){
            return 0;
        }
        else{
            return -INF;
        }
    }
    if(dp1[r][c][mod][num] != -1){
        return dp1[r][c][mod][num];
    }

    int newmod = sub(mod, g[r][c], k);
    int add = g[r][c] + f1(r, c-1, newmod, num-1);
    int noadd = f1(r, c-1, mod, num);
    return dp1[r][c][mod][num] = max(add, noadd);
}

v2<int> dp2;
int f2(int r, int mod){
    if(r==-1){
        if(mod==0){
            return 0;
        }
        else{
            return -INF;
        }
    }
    if(dp2[r][mod] != -1){
        return dp2[r][mod];
    }

    dp2[r][mod] = -INF;
    for(int i = 0; i < k; ++i){
        for(int j = 0; j <= m/2; ++j){
            int cur = f1(r, m-1, i, j);
            int newmod = sub(mod, i, k);
            dp2[r][mod] = max(dp2[r][mod], cur + f2(r-1, newmod));
        }
    }
    return dp2[r][mod];
}

void solve(){
    cin >> n >> m >> k;
    g = fill(n, m, -1);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> g[i][j];
        }
    }
    dp1 = fill(n, m, fill(k, m+1, -1));
    dp2 = fill(n, k, -1);

    int ans = f2(n-1, 0);
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}