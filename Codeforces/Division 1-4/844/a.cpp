#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){
    return v2<T>(r, vector<T>(c, t));
}
#define F first
#define S second

int dist(int a, int b, int c, int d){
    return abs(a-c) + abs(b-d);
}

void solve(){
    int  w, d, h;
    cin >> w >> d >> h;
    int a, b, f, g;
    cin >> a >> b >> f >> g;

    int x = a + h + dist(0, b, f, g);
    int y = w-a + h + dist(w, b, f, g);
    int z = b + h + dist(a, 0, f, g);
    int v = d-b + h + dist(a, d, f, g);

    int ans = min({x, y, z, v});
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