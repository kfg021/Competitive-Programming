#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){
    return v2<T>(r, vector<T>(c, t));
}
#define F first
#define S second

struct SegTree{
    inline int my_log(int x){ return 31-__builtin_clz(x); }
    inline int getSz(int x){ return 1<<(my_log((x<<1)-1)+1); }

    ll(*combine)(ll, ll);
    ll identity;

    int n;
    vector<ll> st;
    vector<pair<int, int>> range;

    SegTree(){}
    SegTree(const vector<int>& a, ll(*combine)(ll, ll), ll identity){
        this->combine = combine;
        this->identity = identity;

        int s = a.size();
        if(s==0) return;

        n = getSz(s);
        st = vector<ll>(n);
        range = vector<pair<int, int>>(n);

        for(int i = 0; i < s; ++i){
            // set st[i+sz/2] using a[i]
            st[i+n/2] = a[i];
        }
        for(int i = 0; i < n/2; ++i) range[i+n/2] = {i, i};

        for(int i = n/2-1; i > 0; --i){
            // set st[i] using st[i*2] and st[i*2+1]
            st[i] = combine(st[i*2], st[i*2+1]);

            range[i] = {range[i*2].F, range[i*2+1].S};
        }
    }

    void update(int ind, ll val){
        // set st[n/2+ind] with val
        st[n/2+ind] = val;

        int i = (n/2+ind)/2;
        while(i > 0){
            // recalculate st[i] using st[i*2] and st[i*2+1]
            st[i] = combine(st[i*2], st[i*2+1]);

            i /= 2;
        }
    }

    ll getRange(int l, int r, int ind){
        int rl = range[ind].F, rr = range[ind].S;
        if(rl == l && rr == r){
            // full overlap, return st[ind]
            return st[ind];
        }
        else if(max(l, rl) <= min(r, rr)){
            // partial overlap, merge child answers
            ll ls = getRange(l, min(r, range[ind*2].S), ind*2), rs = getRange(max(l, range[ind*2+1].F), r, ind*2+1);
            return combine(ls, rs);
        }
        else{
            // no overlap, return IDENTITY
            return identity;
        }
    }

    ll query(int l, int r){
        ll q = getRange(l, r, 1);
        return q;
    }
};

ll my_max(ll a, ll b){
    return max(a, b);
}


void solve(){
    int n, m;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    cin >> m;
    vector<int> x(m);
    for(int i = 0; i < m; i++){
        cin >> x[i];
    }

    for(int i = 0; i < n; i++){
        if(b[i] > a[i]){
            cout << "NO\n";
            return;
        }
    }

    map<int,int> razors;
    for(int i = 0; i < m; i++){
        razors[x[i]]++;
    }

    map<int,vector<int>> mp;
    for(int i = 0; i < n; i++){
        mp[b[i]].push_back(i);
    }

    SegTree st(b, my_max, 0);
    for(auto& p : mp){
        int hair = p.F; 
        vector<int>& v = p.S;
  
        vector<pair<int,int>> range;
        for(int i : v){
            if(a[i] == b[i]){
                continue;
            }
            if(range.empty() || (i > range.back().S + 1)){
                range.push_back({i, i});
            }
            else{
                range.back().S++;
            }
        }
        
        int s = range.size();

        int needed = s;
        for(int i = 0; i < s-1; i++){
            int l = range[i].S+1;
            int r = range[i+1].F-1;
            ll q = st.query(l, r);
            if(q <= hair){
                needed--;
            }
        }
        if(needed > razors[hair]){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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