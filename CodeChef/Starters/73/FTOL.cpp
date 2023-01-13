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

    function<ll(ll, ll)> combine;
    ll identity;

    int n;
    vector<ll> st;
    vector<pair<int, int>> range;

    SegTree(){}
    SegTree(const vector<int>& a, function<ll(ll, ll)> combine, ll identity){
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

struct SumSegTree : SegTree {
    SumSegTree(){}
    SumSegTree(const vector<int>& a): SegTree(a, [](ll a, ll b){ return a + b; }, 0){}
};

struct XorSegTree : SegTree {
    XorSegTree(){}
    XorSegTree(const vector<int>& a): SegTree(a, [](ll a, ll b){ return a ^ b; }, 0){}
};

struct MinSegTree : SegTree {
    MinSegTree(){}
    MinSegTree(const vector<int>& a): SegTree(a, [](ll a, ll b){ return min(a, b); }, 1e18){}
};

struct MaxSegTree : SegTree {
    MaxSegTree(){}
    MaxSegTree(const vector<int>& a): SegTree(a, [](ll a, ll b){ return max(a, b); }, -1e18){}
};


bool sort_col(const pair<int,int>& a, const pair<int,int>& b){
    if(a.S == b.S) return a.F < b.F;
    return a.S < b.S;
}

int pos(const vector<pair<int,int>>& a, const pair<int,int>& p){
    int index = distance(a.begin(), lower_bound(a.begin(), a.end(), p, sort_col));
    return index;
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int,int>> a(k);
    for(int i = 0; i < k; i++){
        cin >> a[i].F >> a[i].S;
    }

    if(k == 0){
        cout << n+m-2 << "\n";
        return;
    }

    sort(a.begin(), a.end(), sort_col);
    
    MaxSegTree st(vector<int>(k, 0));

    vector<pair<int,int>> b = a;
    sort(b.begin(), b.end(), greater<pair<int,int>>());

    vector<pair<pair<int,int>, int>> row;
    int max_row = 0;
    for(auto& p : b){
        if(!row.empty() && p.F < row.back().F.F){
            max_row = 0;
            for(auto& q : row){
                st.update(pos(a, q.F), q.S);
            }
            row.clear();
        }

        int pos_down = pos(a, {p.F+1, p.S});
        int pos_diag = pos(a, {p.F+1, p.S+1});

        int no_take_max = pos_down < k ? max(max_row, (int)st.query(pos_down, k-1)) : max_row;
        int take_max = 0;
        if (p.F+1 <= n && p.S+1 <= m){
            take_max = 1 + ((pos_diag < k) ? st.query(pos_diag, k-1) : 0);
        }

        int my_max = max(take_max, no_take_max);
        row.push_back({p, my_max});
        max_row = max(max_row, my_max);
    }

    int remove = max(max_row, (int)st.query(0, k-1));
    int ans = n+m-2 - remove;
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
