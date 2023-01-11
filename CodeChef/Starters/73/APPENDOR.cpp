#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){
    return v2<T>(r, vector<T>(c, t));
}
#define F first
#define S second

bool bit(int x, int i){
    return (x>>i) & 1;
}

void solve(){
    int n, y;
    cin >> n >> y;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int o = 0;
    for(int i = 0; i < n; i++){
        o |= a[i];
    }

    int ans = 0;
    for(int i = 25; i >= 0; i--){
        if(bit(y, i) && !bit(o, i)){
            ans |= 1<<i;
        }
    }

    if((o | ans) == y){
        cout << ans << "\n";
    }
    else{
        cout << "-1\n";
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
