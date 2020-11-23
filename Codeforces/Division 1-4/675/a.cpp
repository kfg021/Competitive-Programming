/*
All we have to do is make sure that the fourth side of the quadrilateral
is smaller than the sum of the three other sides.
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

void solve(){
    vector<ll> a(3);
    cin >> a[0] >> a[1] >> a[2];

    sort(a.begin(), a.end());

    cout << a[1]+a[2]-a[0] << "\n";
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