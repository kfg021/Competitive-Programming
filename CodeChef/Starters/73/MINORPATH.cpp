#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){
    return v2<T>(r, vector<T>(c, t));
}
#define F first
#define S second

struct BIT{
    int n;
    vector<ll> bit;

    BIT(){}
    BIT(const vector<int>& a){
        n = (int)a.size()+1;
        bit = vector<ll>(n, 0);
        for(int i = 1; i < n; ++i){
            bit[i] += a[i-1];
            int j = i + (i&-i);
            if(j < n){
                bit[j] += bit[i];
            }
        }
    }

    void update(int i, ll x){
        ++i;
        while(i < n){
            bit[i] += x;
            i += i&-i;
        }
    }

    ll query(int i){
        ++i;
        ll ans = 0;
        while(i != 0){
            ans += bit[i];
            i -= i&-i;
        }
        return ans;
    }

    ll query(int l, int r){
        return query(r) - query(l-1);
    }
};

int n;
vector<int> a;

bool possible(const vector<bool>& legal, const vector<bool>& b){
    BIT dp(vector<int>(n, 0));
    dp.update(n-1, legal[n-1] && !b[n-1]);
    for(int i = n-2; i >= 0; i--){
        if(legal[i] && !b[i]){
            int start = i+1;
            int end = min(i + a[i], n-1);
            if(start <= end){
                if(dp.query(start, end) > 0){
                    dp.update(i, 1);
                }
            }
        }
    }
    return dp.query(0, 0);
}

bool possible_full(const vector<bool>& legal){
    return possible(legal, vector<bool>(n, 0));
}

const int BITS = 25;

void solve(){
    cin >> n;
    a = vector<int>(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<bool> legal(n, true);
    if(!possible_full(legal)){
        cout << "-1\n";
        return;
    }

    int ans = 0;
    for(int bit = BITS; bit >= 0; bit--){
        vector<bool> b(n);
        for(int i = 0; i < n; i++){
            b[i] = (a[i]>>bit) & 1;
        }
        bool good = false;
        if(possible(legal, b)){
            vector<bool> new_legal = legal;
            for(int i = 0; i < n; i++){
                if(b[i]){
                    new_legal[i] = false;
                }
            }
            if(possible_full(new_legal)){
                good = true;
                legal = new_legal;
            }
        }
        
        if(!good){
            ans |= 1<<bit;
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
