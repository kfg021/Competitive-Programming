/*
My solution for this problem is to first find all the location of "KICK"
and "START". Since there are no overlapping characters, this
is not too difficult. For each instance of "KICK", we add the amount of
times "START" appears after it to find our answer.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    
    vector<int> kick, start;
    for(int i = 0; i < n; ++i){
        if(i+4 <= n && s.substr(i, 4) == "KICK"){
            kick.push_back(i);
        }
        else if(i+5 <= n && s.substr(i, 5) == "START"){
            start.push_back(i);
        }
    }

    vector<int> safter(n, 0);
    for(int i : start){
        safter[i] = 1;
    }
    for(int i = n-2; i >= 0; --i){
        safter[i] += safter[i+1];
    }

    ll ans = 0;
    for(int i : kick){
        ans += safter[i];
    }

    cout << ans << "\n";
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
