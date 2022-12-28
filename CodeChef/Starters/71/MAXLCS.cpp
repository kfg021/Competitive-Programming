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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int ans = 1e9;
    queue<pair<int,int>> r;
    for(int i = 0; i < n; i++){
        if(r.empty() || s[i] != s[r.back().S]){
            r.push({i, i});
        }
        else{
            r.back().S++;
        }

        assert(!r.empty());
        int end = r.back().S;
        int start = r.front().F;
        if(end-start+1 > k){
            r.front().F++;
            if(r.front().F > r.front().S){
                r.pop();
            }
        }



        if(i >= k-1){
            if(s[i] == '0'){
                ans = min(ans, (int)r.size());
            }
            else{
                ans = min(ans, (int)r.size()-1);
            }
        }
    }

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
