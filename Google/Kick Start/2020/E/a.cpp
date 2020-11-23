/*
All arithmetic sequences have a constant differnece between two adjacent
terms. Knowing this, the problem becomes equivalent to finding the largest
subarray of equal differences. First, we create an array which stores
a[i+1]-a[i] for all i, and we find the largest contigous subarray of a
single element. Our final answer will be this value plus 1 (since a difference
array of length x will have x+1 terms).
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >>a[i];

    vector<int> diff(n-1);
    for(int i = 1; i < n; ++i) diff[i-1] = a[i]-a[i-1];

    const int INF = 1e9+5;
    int ans = 0;
    int cur = INF;
    int streak = 0;
    for(int i = 0; i < n-1; ++i){
        if(diff[i]==cur){
            ++streak;
        }
        else{
            streak = 1;
            cur = diff[i];
        }
        ans = max(ans, streak);
    }

    cout << ans+1 << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for(int i = 1; i <= T; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
