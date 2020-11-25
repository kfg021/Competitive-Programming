/*
Iterate over all possible values of x. We can find the maximum of the first
x elements using a prefix array. Let m be this maximum. We can find all
values of y such that the minimum of the middle y elements is m, and all
values of z such that the maximum of the last z values is m, using binary
search. If these two ranges overlap, we can construct an answer.

We can use a suffix array to find the maximum in the last z elements,
and a segment tree to find the minimum in the middle y
elements.
*/


#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
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
            return st[ind];
        }
        else if(max(l, rl) <= min(r, rr)){
            ll ls = getRange(l, min(r, range[ind*2].S), ind*2), rs = getRange(max(l, range[ind*2+1].F), r, ind*2+1);
            
            // partial overlap, merge child answers
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

int n;
SegTree st;
vector<int> pref, suf;

int find(int i, bool left, bool between){
    int prefmax = pref[i];
    int ans = -1;
    
    int lo = i+1;
    int hi = n-1;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        int q = between ? st.query(i+1, mid) : suf[mid];
        if(q == prefmax){
            ans = mid;
            if(left){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        else if(q < prefmax){
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }

    return ans;
}

bool printans(int x, int y){
    int z = n-x-y;
    if(x>0 && y>0 && z>0){
        cout << "YES\n" << x << " " << y << " " << z << "\n";
        return true;
    }
    return false;
}

void solve(){
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    pref = suf = vector<int>(n);
    pref[0] = a[0];
    for(int i = 1; i < n; ++i){
        pref[i] = max(a[i], pref[i-1]);
    }
    suf[n-1] = a[n-1];
    for(int i = n-2; i >= 0; --i){
        suf[i] = max(a[i], suf[i+1]);
    }
    st = SegTree(a, [](ll a, ll b){return min(a, b);}, 1e9);

    for(int i = 0; i < n; ++i){
        pair<int,int> mid = {find(i, true, true), find(i, false, true)};
        pair<int,int> suf = {find(i, true, false), find(i, false, false)};

        if(mid.F==-1 || mid.S==-1 || suf.F==-1 || suf.S==-1){
            continue;
        }
        for(int endmid : {mid.F, mid.S}){
            if(endmid+1 >= suf.F && endmid+1 <= suf.S){
                if(printans(i+1, endmid-i)){
                    return;
                }
            }
        }
        for(int startsuf : {suf.F, suf.S}){
            if(startsuf-1 >= mid.F && startsuf-1 <= mid.S){
                if(printans(i+1, startsuf-1-i)){
                    return;
                }
            }
        }
    }
    cout << "NO\n";
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