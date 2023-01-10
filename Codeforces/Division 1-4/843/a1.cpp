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
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            string a, b, c;
            for(int k = 0; k < n; k++){
                if(k < i) a += s[k];
                else if(k <= j) b += s[k];
                else c += s[k];
            }
            if(a.empty() || b.empty() || c.empty()) continue;
            if((a <= b && c <= b) || (b <= a && b <= c)){
                cout << a << " " << b << " " << c << "\n";
                return;
            }
        }
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