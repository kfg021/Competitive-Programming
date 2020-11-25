/*
We can use a frequency array to count the number of occurences of each
number. Take the min over all numbers that appear only once. Loop through
the array to retrieve the index of this value.
*/

#include <bits/stdc++.h> 
using namespace std;
 
void solve(){
    int n;
    cin >> n;
    vector<int> a(n), cnt(n, 0);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        --a[i];
        ++cnt[a[i]];
    }
 
    int mn = 1e9;
    for(int i = 0; i < n; ++i){
        if(cnt[i]==1){
            mn = min(mn, i);
        }
    }
 
    if(mn == 1e9){
        cout << "-1\n";
    }
    else{
        for(int i = 0; i < n; ++i){
            if(a[i]==mn){
                cout << i+1 << "\n";
                return;
            }
        }
        assert(false);
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