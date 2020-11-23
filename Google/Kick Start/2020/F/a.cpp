/*
We can determine the number of times a person with d dollars has to
wait with the formula ceil(d/x). Then, we sort the people based on this
value, tiebreaking by their position on the original line.
*/

#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    vector<pair<int, int>> times(n);
    for(int i = 0; i < n; ++i){
        times[i] = {(a[i]+x-1)/x, i};
    }
    sort(times.begin(), times.end());
    
    for(int i = 0; i < n; ++i){
        cout << times[i].S+1 << " ";
    }
    cout << "\n";
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