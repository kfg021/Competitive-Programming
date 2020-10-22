/*
If all districts belong to the same gang, the answer is NO.
Otherwise, the answer is YES. We will always be able to construct the
answer. One possible construction is to place the gangs in some order, 
and to choose one district that belongs to gang i and connect it to all
districts that belong to gang i+1. We might still have some districts 
from the first gang to connect, so we just connect them all to the first
district of gang 2.
*/

#include <bits/stdc++.h> 
using namespace std;
#define F first
#define S second

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    map<int, vector<int>> g;
    for(int i = 0; i < n; ++i){
        g[a[i]].push_back(i);
    }

    if((int)g.size()<=1){
        cout << "NO\n";
        return;
    }

    vector<pair<int, int>> ans;
    for(auto it = g.begin(); it != prev(g.end()); ++it){
        vector<int>& begin = it->S; 
        vector<int>& end = next(it)->S;
        for(int i : end){
            ans.push_back({begin[0], i});
        }

        if(it==g.begin()){
            for(int i = 1; i < (int)begin.size(); ++i){
                ans.push_back({begin[i], end[0]});
            }
        }
    }

    cout << "YES\n";
    for(auto& a : ans){
        cout << a.F+1 << " " << a.S+1 << "\n";
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