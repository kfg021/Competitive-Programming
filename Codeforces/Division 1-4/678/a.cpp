/*
The thing to notice is that this double summation is simply equivalent to
the sum of the array. This is because each element will be counted i times,
where i is its index (1 based). However, we divide each element by i.
Therefore, the total contribution of each element is a[i] * i / i = a[i].
So all we need to do make sure that the total sum of all elements is equal
to the desired sum.
*/

#include <bits/stdc++.h> 
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    int s = 0;
    for(int i : a) s+=i;

    if(s==m){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
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