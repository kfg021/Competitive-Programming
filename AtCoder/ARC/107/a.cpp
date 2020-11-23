/*
It can be shown that this sum is equivalent to 
    (sum(a=1, A) a) * (sum(b=1, B) b) * (sum(c=1, C) c) .
We can calculate each component with the formula
    1+2+3+...+x = x*(x+1) / 2 .
We multiply the components together to get the final answer.
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

const int MOD = 998244353;
inline int add(int a, int b){ return (a+b)%MOD; }
inline int sub(int a, int b){ return ((a-b)%MOD + MOD)%MOD; }
inline int mul(int a, int b){ return ((ll)a*b)%MOD; }

int sum(int x){
    return ((ll)x*(x+1))/2 % MOD;
}

void solve(){
    int a,b,c;
    cin >> a >> b >> c;

    int ans = 1;
    ans = mul(ans, sum(a));
    ans = mul(ans, sum(b));
    ans = mul(ans, sum(c));
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}