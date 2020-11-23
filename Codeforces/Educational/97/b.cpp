/*
Define a group to be a contigous range of numbers we need to change.
It turns out that the answer is equivalent to the number of such groups
in the original string. Since the final string can be either be 1010...
or 0101..., we count the number of groups in both cases and take the min.
*/

#include <bits/stdc++.h> 
using namespace std;
#define F first
#define S second
 
int getmin(string& s){
    int n = s.size();
    vector<pair<int,int>> ranges;
    for(int i = 0; i < n; ++i){
        if(s[i]-'0' != i%2){
            if(ranges.empty() || ranges.back().S < i-1){
                ranges.push_back({i, i});
            }
            else{
                ++ranges.back().S;
            }
        }
    }
    return ranges.size();
}
 
void flip(string& s){
    for(char& c : s){
        if(c=='0') c = '1';
        else c = '0';
    }
}
 
void solve(){
    int n;
    string s;
    cin >> n >> s;
 
    int ans = getmin(s);
    flip(s);
    ans = min(ans, getmin(s));
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