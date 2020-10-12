/*
Let's consider the contribution of each suffix to the final sum. Each suffix
will be counted n-l times, where l is the length of the suffix. For the
prefixes, it gets more complicated. The issue is that we cannot simply add
the prefixes, since they will be not be aligned with each other.
Consider the example s = 1234. The prefix 12 will be counted twice,
in both 124 and 12. However its contribution is NOT 12*2 = 24, but 
12*(10+1) = 132. We can fix this problem by multipling each prefix by
sum(k=0, x-1)(10^k) where x is its contribution. We will precompute the
values of this sum and the powers of 10.
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
inline int add(int a, int b){ return (a+b)%MOD; }
inline int sub(int a, int b){ return ((a-b)%MOD + MOD)%MOD; }
inline int mul(int a, int b){ return ((ll)a*b)%MOD; }

void solve(){
    string s;
    cin >> s;
    int n = s.size();

    vector<int> p10(n+1);
    p10[0] = 1;
    for(int i = 1; i <= n; ++i){
        p10[i] = mul(10, p10[i-1]);
    }

    vector<int> pref10(n+1);
    pref10[0] = 1;
    for(int i = 1; i <= n; ++i){
        pref10[i] = add(pref10[i-1], p10[i]);
    }

    int ans = 0;

    int sum = 0;
    for(int i = 0; i < n-1; ++i){
        sum = mul(10, sum);
        sum = add(sum, s[i]-'0');
        ans = add(ans, mul(sum, pref10[n-i-2]));
    }

    sum = 0;
    for(int i = n-1; i > 0; --i){
        sum = add(sum, mul(p10[n-1-i], s[i]-'0'));
        ans = add(ans, mul(sum, i));
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}