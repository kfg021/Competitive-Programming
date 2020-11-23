/*
We are given that n is even. This helps us because we can consider the
array in chunks of size 2. For every tuple (x, y), we can add (-y, x) to
b. This will make xy-yx = 0 for each chunk. Notice that this problem is
similar to finding perpendicular vectors in multidimensional space.
*/

#include <bits/stdc++.h> 
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    for(int i = 0; i < n-1; i+=2){
        cout << -a[i+1] << " " << a[i] << " ";
    }
    cout << "\n";
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