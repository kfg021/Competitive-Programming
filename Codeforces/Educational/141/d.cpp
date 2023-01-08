#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){
    return v2<T>(r, vector<T>(c, t));
}
#define F first
#define S second

const int MOD = 998244353;
inline int add(int a, int b){ return (a+b)%MOD; }
inline int sub(int a, int b){ return ((a-b)%MOD + MOD)%MOD; }
inline int mul(int a, int b){ return ((ll)a*b)%MOD; }
int my_pow(int a, int b){
    int ans = 1;
    while(b){
        if(b&1) ans = mul(ans, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}
inline int my_div(int a, int b){ return mul(a, my_pow(b, MOD-2)); } 

int n;
vector<int> a;

const int MAX_NUM = 305*300 + 5;
const int LEN = 2*MAX_NUM + 1;
int dp[300][LEN][2];

int pos(int x){
    return MAX_NUM + x;
}

int f(int i, int x, bool plus){
    if(i+2 >= n) return 1;
    if(dp[i][pos(x)][plus] != -1) return dp[i][pos(x)][plus];

    int y = a[i+1];
    if(plus) y += x;
    else y -= x;

    int ans = f(i+1, y, true);
    if(y != 0) ans = add(ans, f(i+1, y, false));

    dp[i][pos(x)][plus] = ans;
    return ans;
}

void solve(){
    cin >> n;
    a = vector<int>(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));

    int ans = f(1, a[1], true);
    if(a[1] != 0) ans = add(ans, f(1, a[1], false)); 
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}