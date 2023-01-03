/*
Since the bounds of the summation are symmetrical, we can rewrite it as
sum(i=1, n) sum(j=1, n) sum(k=1, n) (x_i & x_j) * (x_i | x_k) .

Now, iterate over i from 1 to n. We can solve the two parts separately and
multiply the results. Count the total number of set bits in each of the 60
positions, and let bits be an array with this information. 

To find the bitwise and, we can consider the total contribution of each bit
to the answer. Iterate b over all 60 bits. If the current bit is set in a[i],
we will add 2^b * bits[b] to the answer.

For the bitwise or, we use a similar method. Iterate b over all 60 bits, and if the
current bit is set in a[i], add 2^b * n to the answer. Otherwise, add 2^b * bits[b].

The final answer will be the multiplication of the previous two results.
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

struct ModInt{
    int val;
    ModInt(){}
    ModInt(ll x){ val = x % MOD; }
};

ModInt operator+(ModInt a, ModInt b){ return ModInt(a.val + b.val); }
void operator+=(ModInt& a, ModInt b){ a = a + b; }
void operator++(ModInt& a){ a += 1; }

ModInt operator-(ModInt a, ModInt b){ return ModInt((a.val - b.val) % MOD + MOD); }
void operator-=(ModInt& a, ModInt b){ a = a - b; }
void operator--(ModInt& a){ a -= 1; }

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

ModInt operator/(ModInt a, ModInt b){ return a * (my_pow(b, MOD-2)); }
void operator/=(ModInt& a, ModInt b){ a = a / b; }

bool operator==(ModInt a, ModInt b){ return a.val == b.val; }

ostream& operator<<(ostream& os, ModInt a){ return os << a.val; }

void solve(){
    int n;
    cin >> n;

    vector<ll> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    vector<int> bits(60, 0);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 60; ++j){
            if((a[i] >> j) & 1){
                ++bits[j];
            }
        }
    }

    ModInt ans = 0;

    for(int i = 0; i < n; ++i){
        ModInt and_sum = 0, or_sum = 0;
        for(int b = 0; b < 60; ++b){
            ModInt p2(1LL<<b);
            if((a[i] >> b) & 1){
                and_sum += p2 * bits[b];
                or_sum += p2 * n;
            }
            else{
                or_sum += p2 * bits[b];
            }
        }
        ans += and_sum * or_sum;
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