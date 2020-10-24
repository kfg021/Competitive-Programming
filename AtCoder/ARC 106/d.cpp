/*
During the contest, I was not able to solve this problem. I came up with a
solution that ran in O(n * k^2) time, which unfortunately was too slow.
This solution runs in O(n*k + k^2), which is fast enough.

This problem very math-heavy.
Let's consider calcluating the sum for one value of x. The binomial theorem
is very helpful here. We can represent (a+b)^x as
    a^x + a^(x-1) * b * (x choose 1) + a^(x-2) * b^2 * (x choose 2) + ... + b^x .

We can express the total contribution of the (x choose y) term over all pairs
(a[i], a[j]) as
    (x choose y) * ( sum(i=0, n-1)(a[i]^y) * sum(j=0, n-1)(a[j]^(x-y)) - sum(l=0, n-1)(a[l]^x) ) / 2 .
    We divide by 2 since the tuple (a[i], a[j]) is equivalent to (a[j], a[i]).

These power sums and choose functions can be precomputed in O(n*k) time and
O(k^2) time, respectively. This allows us to calculate the answer for each x
in O(k) time.
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }

const int MOD = 998244353;
inline int add(int a, int b){ return (a+b)%MOD; }
inline int sub(int a, int b){ return ((a-b)%MOD + MOD)%MOD; }
inline int mul(int a, int b){ return ((ll)a*b)%MOD; }
int pwr(int a, int b){
    if(!b) return 1;
    int temp = pwr(a, b/2);
    if(b%2) return mul(mul(temp, temp), a);
    return mul(temp, temp);
}

const int modinv2 = pwr(2, MOD-2);
inline int dvd2(int a){ return mul(a, modinv2); }

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    v2<int> ch = fill(k+1, k+1, -1);
    for(int i = 0; i <= k; ++i) ch[i][0] = 1; 
    for(int j = 1; j <= k; ++j) ch[0][j] = 0; 
    for(int i = 1; i <= k; ++i){
        for(int j = 1; j <= k; ++j){
            ch[i][j] = add(ch[i-1][j-1], ch[i-1][j]);
        }
    }

    v2<int> pwrs = fill(n, k+1, -1);
    for(int i = 0; i < n; ++i){
        pwrs[i][0] = 1;
         for(int j = 1; j <= k; ++j){
            pwrs[i][j] = mul(pwrs[i][j-1], a[i]);
        }
    }

    vector<int> sums(k+1, 0);
    for(int i = 0; i <= k; ++i){
        for(int j = 0; j < n; ++j){
            sums[i] = add(sums[i], pwrs[j][i]);
        }
    }

    for(int i = 1; i <= k; ++i){
        int ans = 0;
        for(int j = 0; j <= i; ++j){
            int s = mul(sums[j], sums[i-j]);
            s = sub(s, sums[i]);
            s = mul(s, ch[i][j]);
            ans = add(ans, s);
        }
        ans = dvd2(ans);
        cout << ans << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}