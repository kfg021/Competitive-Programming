/*
This problem is equivalent to finding the maximum distance in the grid
from (r, c). The answer must be the distance to one of the four corners.
We can test them all and take the max.
*/

#include <bits/stdc++.h> 
using namespace std;
#define F first
#define S second

int manh(int a, int b, int c, int d){
    return abs(a-c) + abs(b-d);
}

void solve(){
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    --r, --c;

    int ans = 0;

    vector<pair<int,int>> corners = {{0, 0}, {n-1, 0}, {0, m-1}, {n-1, m-1}};
    for(auto& pt : corners){
        ans = max(ans, manh(r, c, pt.F, pt.S));
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