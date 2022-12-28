#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){
    return v2<T>(r, vector<T>(c, t));
}
#define F first
#define S second

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    map<int,int> m;
    for(int i = 0; i < n; i++){
        m[a[i]]++;
    }

    bool even = true;
    for(auto& p : m){
        if(p.second%2==1){
            even = false;
        }
    }

    if(even){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
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
