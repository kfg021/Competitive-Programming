/*
(Works for both versions of the problem).
We will solve the problem with a construction.
We will take the largest n/2 elements (rounded up) and use them to
surround the rest of the elements. If n is even there are duplicates,
this is not always optimal. In particular, it is possible that we are
missing one point. Take the example 6 6 6 6 4 2. This method would produce
the array 6 6 6 4 6 2. However, we are missing the point from the 2,
since the second 6 does not give us any points. If this happens, we simply
swap this element with the last element, obtaining the optimal 6 2 6 4 6 6.
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }
#define F first
#define S second

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());

    vector<int> ans(n, -1);
    for(int i = 0; i < (n+1)/2; ++i){
        ans[i*2] = a[i];
    }
    for(int i = 0; i < n-(n+1)/2; ++i){
        ans[i*2+1] = a[i+(n+1)/2];
    }

    int amt = 0;
    int bad = -1;
    for(int i = 1; i < n-1; i+=2){
        if(ans[i-1]>ans[i] && ans[i+1]>ans[i]){
            ++amt;
        }
        else if(bad==-1) bad=i;
    }
    if(n%2==0 && amt != (n-1)/2){
        int temp = ans[bad];
        ans[bad] = ans[n-1];
        ans[n-1] = temp;  
        if(ans[bad-1]>ans[bad] && ans[bad+1]>ans[bad]){
            ++amt;
        }
    }

    cout << amt << "\n";
    for(int i : ans) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}