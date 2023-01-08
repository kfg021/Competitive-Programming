#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){
    return v2<T>(r, vector<T>(c, t));
}
#define F first
#define S second

int n, m;
vector<pair<int,int>> s;
map<int,int> loc;
vector<ll> pref;


ll getPref(int len, int no){
    ll sum = len-1 >= 0 ? pref[len-1] : 0;
    if(no != -1){
        if(loc[no] <= len-1){
            assert(len < n);
            sum -= s[loc[no]].F;
            sum += s[len].F;
        }
    }
    return sum;
}

void solve(){
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    s = vector<pair<int,int>>(n);
    for(int i = 0; i < n; i++){
        s[i] = {a[i], i};
    }
    sort(s.begin(), s.end());

    loc.clear();
    for(int i = 0; i < n; i++){
        loc[s[i].S] = i;
    }

    pref = vector<ll>(n);
    pref[0] = s[0].F;
    for(int i = 1; i < n; i++){
        pref[i] = pref[i-1] + s[i].F;
    }

    for(int place = 1; place <= n; place++){
        ll cost1 = a[n-place] + getPref(n-1-place, n-place);
        ll cost2 = getPref(n+1-place, -1);

        if(min(cost1, cost2) <= m){
            cout << place << "\n";
            return;
        }
    }

    cout << n+1 << "\n";
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