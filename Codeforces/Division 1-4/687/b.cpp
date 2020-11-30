/*
Since there are only 100 possible colors, we can iterate over the color
to paint all houses. Let c be the current color. If we reach a house that
has a color other than c, then we need to paint it. We will paint the next
k houses and add one to the current score. Otherwise, we can skip this house
and move to the next one.
The answer will be the minimum score over all colors.
*/

#include <bits/stdc++.h> 
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    
    int ans = 1e9;
    for(int c = 1; c <= 100; ++c){
        int my_ans = 0;
        int i = 0;
        while(i < n){
            if(a[i] != c){
                i += k;
                ++my_ans;
            }
            else{
                ++i;
            }
        }
        ans = min(ans, my_ans);
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