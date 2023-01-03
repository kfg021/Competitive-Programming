/*
We can iterate over all pairs of points on the x axis. The only valid triangle
formed by these points will be with the point at (0, 1). Let a be the x 
coordinate of the first point, and b be the x coordinate of the second point.
The area will be abs(a - b) / 2 . We will use a set to determine the number
the number of unique areas.

We can work with twice the area instead of the true area to avoid floating point
precision errors.
*/

#include <bits/stdc++.h> 
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    set<int> seen;
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            int area2 = abs(a[i]-a[j]);
            seen.insert(area2);
        }
    }

    cout << seen.size() << "\n";
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