#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9+7; //998244353;

struct ModInt{
    int val;
    ModInt(){}
    ModInt(ll x){ val = x % MOD; }
};

ModInt operator+(ModInt a, ModInt b){ return ModInt(a.val + b.val); }
void operator+=(ModInt& a, ModInt b){ a = a + b; }

ModInt operator-(ModInt a, ModInt b){ return ModInt((a.val - b.val) % MOD + MOD); }
void operator-=(ModInt& a, ModInt b){ a = a - b; }

ModInt operator*(ModInt a, ModInt b){ return ModInt((ll)a.val * b.val); }
void operator*=(ModInt& a, ModInt b){ a = a * b; }

ModInt my_pow(ModInt a, ll b){
    ModInt ans = 1;
    while(b){
        if(b&1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ModInt(ans);
}

ModInt operator/(ModInt a, ModInt b){ return a * (my_pow(b, MOD-2)); } // MOD MUST BE PRIME
void operator/=(ModInt& a, ModInt b){ a = a / b; }

bool operator==(ModInt a, ModInt b){ return a.val == b.val; }

ostream& operator<<(ostream& os, ModInt a){ return os << a.val; }

void solve(){
    int n;
    cin >> n;

    ModInt m = n;
    ModInt ans = ((m*(m+1)*(2*m+1))/6 + ((m-1)*m*(m+1))/3) * 2022;
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for(int i = 0; i < t; ++i){
        solve();
    }
    return 0;
}