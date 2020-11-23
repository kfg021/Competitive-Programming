/*
The answer will be the total number of 0's between the two outermost 1's.
An optimal appraoch is to always slide the leftmost group of books to the right. 
Since we can only move a segment by one each move, the answer cannot possibly be
any lower.
*/

#include <bits/stdc++.h> 
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    int first1 = -1, last1 = -1;
    for(int i = 0; i < n; ++i){
        if(a[i]==1){
            if(first1==-1){
                first1 = i;
            }
            last1 = i;
        }
    }

    int ans = 0;
    for(int i = first1; i <= last1; ++i){
        ans += a[i]==0;
    }
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