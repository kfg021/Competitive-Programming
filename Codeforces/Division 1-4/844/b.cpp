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
    sort(a.begin(), a.end(), greater<int>());

    int ans = 0;
    for(int i = 0; i < n; i++){
        int after = n-1-i;
        if(after >= a[i]){
            if(i==0 || after+1 < a[i-1]){
                ans++;
            }
        }
    }

    bool zero = false;
    for(int i = 0; i < n; i++){
        if(a[i]==0) zero=true;
    }
    if(!zero) ans++;

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