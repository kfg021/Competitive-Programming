#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){
    return v2<T>(r, vector<T>(c, t));
}
#define F first
#define S second

const int BITS = 62;

bool bit(ll n, int b){
    return (n >> b) & 1;
}

void solve(){
    ll n, x;
    cin >> n >> x;

    if(n == x){
        cout << n << "\n";
        return;
    }

    for(int i = BITS; i >= 0; i--){
        if(bit(x, i) > bit(n, i)){
            cout << "-1\n";
            return;
        }
    }

    int firstdiff = -1;
    for(int i = BITS; i >= 0; i--){
        if(firstdiff == -1 && bit(x, i) != bit(n, i)){
            firstdiff = i;
        }
    }

    ll mask = 0;
    for(int i = firstdiff; i >= 0; i--){
        if(bit(n, i)){
            mask |= (1ll<<i);
        }
    }

    ll ans = (1ll<<(firstdiff+1)) - mask + n;

    if((ans & n & x) == x){
        cout << ans << "\n";
    }
    else{
        cout << "-1\n";
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