#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){
    return v2<T>(r, vector<T>(c, t));
}
#define F first
#define S second

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

int n;
v2<int> adj;
vector<bool> vis;
vector<int> a;

const int MAX_BIT = 30;

vector<bool> digits(int x){
    vector<bool> ans;
    for(int i = MAX_BIT; i >= 0; i--){
        ans.push_back((x >> i) & 1);
    }
    return ans;
}

struct Trie{
    set<int> vals;
    array<Trie*,2> ch{};

    void insert(int label, const vector<bool>& v, int start=0){
        if(start > MAX_BIT){
            vals.insert(label);
        }
        else{
            if(ch[v[start]] == nullptr){
                ch[v[start]] = new Trie();  
            }
            ch[v[start]]->insert(label, v, start+1); 
        }
    }

    bool remove(int label, const vector<bool>& v, int start=0){
        if(start > MAX_BIT){
            assert(vals.count(label));
            vals.erase(vals.find(label));
            return vals.empty();
        }
        else{
            bool empty = ch[v[start]]->remove(label, v, start+1);
            if(empty){
                delete ch[v[start]];
                ch[v[start]] = nullptr;
            }
            return empty && ch[!v[start]] == nullptr;
        }
    }
};

ModInt dfs(int u, int x, Trie* t){
    vis[u] = true;
    x ^= a[u];

    auto d = digits(a[u]);
    t->insert(u, d);
    
    int numchildren = 0;
    for(int v : adj[u]){
        numchildren += !vis[v];
    }

    ModInt ans = 0;
    if(numchildren > 0){
        for(int v : adj[u]){
            if(!vis[v]){
                ModInt child = dfs(v, x, t);
                ans += child;
            }
        }
        ans /= numchildren;
    }
    else{
        Trie* cur = t;
        int max_xor = 0;
        auto dx = digits(x);
        for(int i = 0; i <= MAX_BIT; i++){
            if(cur->ch[!dx[i]] != nullptr){
                max_xor |= 1<<(MAX_BIT-i);
                cur = cur->ch[!dx[i]];
            }
            else{
                assert(cur->ch[dx[i]] != nullptr);
                cur = cur->ch[dx[i]];
            }
        }
        ans = max_xor;
    }

    t->remove(u, d);
    return ans;
}


void solve(){
    cin >> n;
    a = vector<int>(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    adj = v2<int>(n);
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vis = vector<bool>(n, false);

    Trie* t = new Trie();
    ModInt ans = dfs(0, 0, t);
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
