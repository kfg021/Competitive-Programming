/*
Notice that 0 and 1 are non-negative and non-prime. A simple construction
for this problem is to place 2x2 boxes of 1's along one of the diagonals.
For example, the here is the construction for n=4:
1 1 0 0
1 1 0 0
0 0 1 1
0 0 1 1
Each row/coulmn will have a sum of 2, which is prime. In the case that n is
odd, this will not quite work since the last row and column will only have
a sum of 1. We can fix this by adding one extra 1 in the last row, and one
extra 1 in the last column. In this case, some rows/columns will have a sum
of 3, but that is fine since 3 is also prime.
*/

#include <bits/stdc++.h> 
using namespace std;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }

void solve(){
    int n;
    cin >> n;

    v2<int> ans = fill(n, n, 0);
    for(int i = 0; i < n; i+=2){
        ans[i][i] = 1;
        if(i+1 < n){
            ans[i][i+1] = 1;
            ans[i+1][i] = 1;
            ans[i+1][i+1] = 1;
        }
        else{
            ans[i][i-1] = 1;
            ans[i-1][i] = 1;
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << ans[i][j] << " ";
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