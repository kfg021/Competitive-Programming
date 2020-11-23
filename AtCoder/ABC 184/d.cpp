/*
We will use dynamic programming for this problem. Our state is 
dp[i][j][k] = the expected number of draws when we start with a bag of i
gold coins, j bronze coins, and k silver coins. In our transition, we
simulate taking one of each possible coin, and multiply the outcome of
the recursive call with the likelihood that said coin will be drawn
from the bag. After doing this for all coin types, we add 1, since we
just performed one operation. The answer will be dp[a][b][c].
*/

#include <bits/stdc++.h> 
using namespace std;
using ld = long double;

const ld INVALID = -1.0L;
ld dp[101][101][101];

ld f(int i, int j, int k){
    if(dp[i][j][k] != INVALID){
        return dp[i][j][k];
    }
    
    if(i==100||j==100||k==100){
        dp[i][j][k] = 0.0L;
    }
    else{
        int tot = i+j+k;
        dp[i][j][k] = 1.0L + (ld)i/tot * f(i+1, j, k) + (ld)j/tot * f(i, j+1, k) + (ld)k/tot * f(i, j, k+1);
    }
    return dp[i][j][k];
}

void solve(){
    int a, b, c;
    cin >> a >> b >> c;

    for(int i = 0; i <= 100; ++i){
        for(int j = 0; j <= 100; ++j){
            for(int k = 0; k <= 100; ++k){
                dp[i][j][k] = INVALID;
            }
        }
    }

    ld ans = f(a, b, c);
    cout << fixed << setprecision(9) << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}