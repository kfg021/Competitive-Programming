/*
Just simulate the problem, stopping once one boulder reaches the end. At
most this will take n * max(h_i) operations, which is small given the constriants.
(n <= 100, h_i <= 100)
*/

#include <bits/stdc++.h> 
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    for(int i = 0; i < k; ++i){
        int cur = 0;
        while(cur != n-1 && a[cur] >= a[cur+1]){
            ++cur;
        }

        if(cur == n-1){
            cout << "-1\n";
            return;
        }
        else{
            ++a[cur];
        }

        if(i==k-1){
            if(cur==n-1){
                cout << "-1\n";
            }
            else{
                cout << cur+1 << "\n";
            }
        }
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