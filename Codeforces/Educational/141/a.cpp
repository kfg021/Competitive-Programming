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
    set<int> s(a.begin(), a.end());
    if(s.size() == 1){
        cout << "NO\n";
        return;
    }

    sort(a.begin(), a.end(), greater<int>());

    int start = 0;
    while(start+1 < n && a[start+1] == a[0]) start++;
    cout << "YES\n";
    for(int i = start; i < n; i++){
        cout << a[i] << " ";
    }
    for(int i = 0; i < start; i++){
        cout << a[i] << " ";
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