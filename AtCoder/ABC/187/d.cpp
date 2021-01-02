/*
If we make a speech in a town, we get a_i + b_i votes, and if we don't, we lose a_i votes.
Therefore, we should sort the districts by (a_i + b_i) - (-a_i) = 2 * a_i + b_i, and greedily
take towns until we have enough votes.
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
#define F first
#define S second

bool comp(pair<int,int>& l, pair<int,int>& r){
    return 2LL*l.F + l.S > 2LL*r.F + r.S;
}

void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i].F >> a[i].S;
    }
    sort(a.begin(), a.end(), comp);

    vector<ll> pref(n), suf(n);
    for(int i = 0; i < n; ++i){
        pref[i] = a[i].F + a[i].S;
        if(i > 0){
            pref[i] += pref[i-1];
        }
    }
    for(int i = n-1; i >= 0; --i){
        suf[i] = a[i].F;
        if(i < n-1){
            suf[i] += suf[i+1];
        }
    }

    for(int i = 0; i < n; ++i){
        if(pref[i] > (i+1 < n ? suf[i+1] : 0)){
            cout << i+1 << "\n";
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}