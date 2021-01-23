/*
This is the "Largest area under histogram" problem.
GeeksForGeeks: https://www.geeksforgeeks.org/largest-rectangle-under-histogram/
LeetCode: https://leetcode.com/problems/largest-rectangle-in-histogram/

For this version, the solution only needs to be in O(n^2) time.
Iterate over the two endpoints. Let these be i and j. Then, the optimal
answer for this reigon will be (j-i+1) * (minimum value between i and j).
Take the maximum answer over all reigons.
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    ll ans = 0;
    for(int i = 0; i < n; ++i){
        int mn = a[i];
        for(int j = i; j < n; ++j){
            mn = min(mn, a[j]);
            ans = max(ans, (ll)(j-i+1) * mn);
        }
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}