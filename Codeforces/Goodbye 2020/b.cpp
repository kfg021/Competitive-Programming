/*
We can use a greedy approach, where we increment an element only if we have
previously seen it. At the end, count the number of seen elements.
*/

#include <bits/stdc++.h> 
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    set<int> seen;
    for(int i = 0; i < n; ++i){
        if(seen.count(a[i])){
            ++a[i];
        }
        seen.insert(a[i]);
    }

    cout << seen.size() << "\n";
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