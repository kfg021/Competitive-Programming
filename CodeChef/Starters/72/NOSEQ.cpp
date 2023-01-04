#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){
    return v2<T>(r, vector<T>(c, t));
}
#define F first
#define S second

ll my_pow(ll a, int b){
    ll ans = 1;
    for(int i = 0; i < b; i++){
        ans *= a;
    }
    return ans;
}

vector<int> digits(ll x, int b){
    vector<int> ans;
    while(x > 0){
        ans.push_back(x%b);
        x /= b;
    }
    return ans;
}

int sign(ll x){
    if(x > 0) return 1;
    if(x < 0) return -1;
    return 0;
}

vector<int> solve(ll n, ll k, ll s){
    vector<int> ans(n, -2);
    while(true){
        vector<int> digs = digits(abs(s), k);

        int l = digs.size();
        bool all01 = true;
        int lastg1 = -1;
        for(int i = 0; i < l; i++){
            if(digs[i] > 1){
                all01 = false;
                lastg1 = i;
            }
        }

        if(all01){
            for(int i = 0; i < l; i++){
                if(i >= n || ans[i] != -2){
                    return {-2};
                }

                ans[i] = sign(s) * digs[i];
            }
            break;
        }

        int first0after = l;
        for(int i = lastg1; i < l; i++){
            if(digs[i] == 0){
                first0after = i;
                break;
            }
        }

        if(first0after >= n || ans[first0after] != -2){
            return {-2};
        }

        ans[first0after] = sign(s);
        if(s > 0) s -= my_pow(k, first0after);
        else s += my_pow(k, first0after);
    }

    for(int i = 0; i < n; i++){
        if(ans[i] == -2) ans[i] = 0;
    }

    return ans;
}

void solve(){
    ll n, k, s;
    cin >> n >> k >> s;

    vector<int> ans = solve(n, k, s);
    for(int i : ans){
        cout << i << " ";
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
