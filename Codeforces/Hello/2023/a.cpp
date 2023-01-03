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
    string s;
    cin >> s;

    int l=0;
    int r=0;
    for(int i = 0; i < n; i++){
        l += (s[i]=='L');
        r += (s[i]=='R');
    }

    if((l==0) || (r==0)){
        cout << "-1\n";
    }
    else{
        for(int i = 0; i < n-1; i++){
            if(s[i] == 'R' && s[i+1] == 'L'){
                cout << "0\n";
                return;
            }
        }

        for(int i = 0; i < n-1; i++){
            if(s[i] == 'L' && s[i+1] == 'R'){
                cout << i+1 << "\n";
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