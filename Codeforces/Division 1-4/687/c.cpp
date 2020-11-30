/*
(explanation assumes 0-based indexing)
We can iterate over the starting position of the ball, from position p to
position n-1. For a given position pos, we will need to remove pos-p spaces,
contributing a cost of (pos-p) * x. We will also need to add a certian
number of squares after pos. We can define a suffix array suf[i] storing
the number of squares we would need to fill if we start at position i.
Therefore, we will also need to add suf[pos] * y to the cost.
We can define suf[i] as 
   suf[i] = { 1-a[i] + suf[i+k] if i+k < n, 1-a[i] otherwise }

The answer will be the minimum cost over all positions.
*/

#include <bits/stdc++.h> 
using namespace std;

void solve(){
    int n, p, k;
    cin >> n >> p >> k;
    --p;
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;

    vector<int> suf(n);
    for(int i = n-1; i >= 0; --i){
        suf[i] = !(s[i]-'0');
        if(i+k < n){
            suf[i] += suf[i+k];
        }
    }

    int ans = 1e9;
    for(int start = p; start < n; ++start){
        int front = (start-p) * y;
        int add = suf[start] * x;
        ans = min(ans, front+add);
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