/*
The last painters are the ones that matter most, since the earlier ones
can get painted over. Therefore, go through the painters backwards. If we
find a painter to paint one of the fences, we can use the other painters
we don't need on a fence that we will repaint later. If we find painters
for all of the fences we need to change, the answer is YES.
*/


#include <bits/stdc++.h> 
using namespace std;
#define F first
#define S second

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), c(m);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];
    for(int i = 0; i < m; ++i) cin >> c[i];

    map<int,vector<int>> good, change;
    for(int i = 0; i < n; ++i){
        if(a[i]==b[i]){
           good[a[i]].push_back(i);
        }
        else{
            change[b[i]].push_back(i);
        }
    }

    vector<int> ans;

    int first = -1;
    for(int i = m-1; i >= 0; --i){
        if(change.count(c[i]) && change[c[i]].size() > 0){
            int ind = change[c[i]].back();
            change[c[i]].pop_back();
            ans.push_back(ind);
            
            if(first==-1) first = ind;
        }
        else if(first == -1){
            if(good.count(c[i]) && good[c[i]].size() > 0){
                int ind = good[c[i]].back();
                ans.push_back(ind);

                if(first==-1) first = ind;
            }
            else{
                cout << "NO\n";
                return;
            }
        }
        else{
            ans.push_back(first);
        }
    }

    int left=0;
    for(auto& p : change){
        left += p.S.size();
    }
    if(left != 0){
        cout << "NO\n";
        return;
    }

    reverse(ans.begin(), ans.end());
    cout << "YES\n";
    for(int i : ans){
        cout << i+1 << " ";
    }
    cout << "\n";
    
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