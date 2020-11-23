/*
Because of small constraints, we can do a brute force. Generate all
possible paths, and check whether the sum of each path equals k.
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }

v2<int> perms(vector<int>& v){
    int s = v.size();
    if(s==0) return {{}};
    
    v2<int> ans;
    for(int i = 0; i < s; ++i){
        vector<int> next = {};
        for(int j = 0; j < s; ++j){
            if(i==j) continue;
            next.push_back(v[j]);
        }
        for(vector<int>& perm : perms(next)){
            perm.insert(perm.begin(), v[i]);
            ans.push_back(perm);
        }
    }
    return ans;
}

void solve(){
    int n, k;
    cin >> n >> k;
    v2<int> t = fill(n, n, -1);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> t[i][j];
        }
    }

    int ans = 0;
    vector<int> cities(n-1);
    for(int i = 0; i < n-1; ++i){
        cities[i] = i+1;
    }
    for(vector<int>& perm : perms(cities)){
        ll sum = t[0][perm[0]] + t[perm[n-2]][0];
        for(int i = 0; i < n-2; ++i){
            sum += t[perm[i]][perm[i+1]];
        }

        ans += sum==k;
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}