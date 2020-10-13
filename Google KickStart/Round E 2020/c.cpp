/*
We will be able to use a group of toys indefinitley if for each toy, 
the sum of the enjoyment scores of all other toys is greater than
the remembrance of the current one. If this holds, the answer will be
"0 INDEFINITELY". If not, there will be some toys which voilate this
condition. We continously remove such toys until we either find a configuration
we can use indefinitley, or we run out of toys. If we run out of toys, the
answer will be the maximum answer we encountered. In order to calculate the
playing time, we will need to know the sum of enjoyments across all remaining toys.
For that, we can use a segment tree. 
Note: I am glossing over a lot of the implementation details here. My solution
is rather complex, so I tried to just give a high-level idea of how it works.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define F first
#define S second

struct SegTree{
    inline int my_log(int a){ return 31-__builtin_clz(a); }
    inline int getSz(int a){ return 1<<(my_log((a<<1)-1)+1); }
    int sz;
    vector<ll> st;
    vector<pair<ll, ll>> range;

    SegTree(int n, vector<ll>& input){
        sz = getSz(n);
        st = vector<ll>(sz);
        range = vector<pair<ll, ll>>(sz);

        for(int i = 0; i < n; ++i){
            // set st[i+sz/2] using input[i]
            st[i+sz/2] = input[i];
        }
        for(int i = 0; i < sz/2; ++i) range[i+sz/2] = {i, i};

        for(int i = sz/2-1; i > 0; --i){
            // set st[i] using st[i*2] and st[i*2+1]
            st[i] = st[i*2] + st[i*2+1];
            range[i] = {range[i*2].F, range[i*2+1].S};
        }
    }

    void update(ll ind, ll val){
        // set st[sz/2+ind] with val
        st[sz/2+ind] = val;
        ll i = (sz/2+ind)/2;
        while(i > 0){
            // recalculate st[i] using st[i*2] and st[i*2+1]
            st[i] = st[i*2] + st[i*2+1];
            i /= 2;
        }
    }

    ll getRange(ll l, ll r, ll ind){
        ll rl = range[ind].F, rr = range[ind].S;
        if(rl == l && rr == r){
            // full overlap, return function of st[ind]
            return st[ind];
        }
        else if(max(l, rl) <= min(r, rr)){
            // partial overlap, merge child answers
            ll ls = getRange(l, min(r, range[ind*2].S), ind*2), rs = getRange(max(l, range[ind*2+1].F), r, ind*2+1);
            return ls+rs;
        }
        else{
            // no overlap, return NULL
            return 0;
        }
    }

    ll query(ll l, ll r){
        ll qans = getRange(l, r, 1);

        // return some function of qans
        return qans;
    }
};

const ll INF = 1e18;

void solve(){
    int n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    vector<ll> input(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i].F >> a[i].S;
        input[i] = a[i].F;
    }

    ll sum = 0;
    for(auto& p : a) sum += p.F;

    //store: [sum-e[i]-r[i], index]
    set<pair<ll, ll>> s;
    for(int i = 0; i < n; ++i){
        s.insert({sum-a[i].F-a[i].S, i});
    }

    SegTree st(n, input);

    ll ans = -1;
    ll bestsz = -1;
    ll off = 0;

    set<ll> bad;
    while(!s.empty()){
        if(s.begin()->F < off){
            bad.insert(s.begin()->S);
            s.erase(s.begin());
        }
        else break;
    }
    if(bad.empty()){
        cout << "0 INDEFINITELY\n";
        return;
    }

    //best before start
    ll ext = 0;
    if(*bad.begin() >= 1) ext = st.query(0, *bad.begin()-1);
    ans = sum + ext;
    bestsz = n;

    while(true){
        ll removed = *bad.begin();
        bad.erase(bad.begin());

        sum -= a[removed].F;
        off += a[removed].F;
        st.update(removed, 0);

        while(!s.empty()){
            if(s.begin()->F < off){
                bad.insert(s.begin()->S);
                s.erase(s.begin());
            }
            else break;
        }

        if(bad.empty()){
            if(!s.empty()){
                ans = INF;
                bestsz = (ll)s.size();
            }
            break;
        }

        ll ext = 0;
        if(*bad.begin() >= 1) ext = st.query(0, *bad.begin()-1);
        ll score = sum + ext;
        ll newsz = (ll)s.size() + (ll)bad.size();
        if(score > ans){
            ans = score;
            bestsz = newsz;
        }
        else if(score == ans){
            bestsz = max(bestsz, newsz);
        }
    }

    cout << n-bestsz << ' ';
    if(ans==INF) cout << "INDEFINITELY\n";
    else cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for(int i = 1; i <= T; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}