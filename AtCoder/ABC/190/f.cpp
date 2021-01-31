/*
First find the number of inversions in the original array (can be done
with a Binary Indexed Tree / Fenwick Tree).

Let's consider the sequences in reverse order (k = n-1 -> k = 0).

To transition from k to k-1, we move an element from the end of the array
to the front. Let x be the element that we are moving. Moving x to the
front will gain us x inversions because it is moved in front of the smaller
elements (0, 1, ..., x-1). We will lose n-1 - x inversions because x is no
longer behind the greater elements (x+1, x+2, ..., n-1).

Starting from the original array, we can get the answer for each value of k
using this method.
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

struct BIT{
    int n;
    vector<ll> bit;

    BIT(){}
    BIT(const vector<int>& a){
        n = (int)a.size()+1;
        bit = vector<ll>(n, 0);
        for(int i = 1; i < n; ++i){
            bit[i] += a[i-1];
            int j = i + (i&-i);
            if(j < n){
                bit[j] += bit[i];
            }
        }
    }

    void update(int i, ll x){
        ++i;
        while(i < n){
            bit[i] += x;
            i += i&-i;
        }
    }

    ll query(int i){
        ++i;
        ll ans = 0;
        while(i != 0){
            ans += bit[i];
            i -= i&-i;
        }
        return ans;
    }

    ll query(int l, int r){
        return query(r) - query(l-1);
    }
};

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    vector<ll> ans(n, -1);
    ans[0] = 0;
    BIT b(vector<int>(n, 0));
    for(int i = n-1; i >= 0; --i){
        ans[0] += b.query(a[i]-1);
        b.update(a[i], 1);
    }

    for(int k = 1; k < n; ++k){
        int move = a[(n-1 + n - (k-1)) % n];

        ans[(n-k)%n] = ans[(n - (k-1)) % n];
        ans[(n-k)%n] += move;
        ans[(n-k)%n] -= n-1 - move;
    }

    for(ll i : ans){
        cout << i << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}