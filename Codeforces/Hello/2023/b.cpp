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

    if(n==3){
        cout << "NO\n";
    }
    else if(n%2==0){
        cout << "YES\n";
        for(int i = 0; i < n; i++){
            if(i%2==0) cout << "-1 ";
            else cout << "1 ";
        }
        cout << "\n";
    }
    else{
        cout << "YES\n";
        int a = 1;
        int x = (1-n/2) * a;
        int y = a-x;
        for(int i = 0; i < n; i++){
            if(i%2==0) cout << x << " ";
            else cout << y << " ";
        }
        cout << "\n";
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