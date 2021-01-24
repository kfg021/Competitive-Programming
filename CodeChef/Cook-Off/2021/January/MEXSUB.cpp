/*
An important observation is that the MEX of the array is the only possible
option for m. This can be derived from the fact that every element must
belong to exactly one group. 
Because of this, assume m = MEX(a).

We can use dynamic programming, where dp[i] = the answer for the suffix 
starting at element i. We will compute these dp states backwards (from
dp[n] to dp[0]). The base case is dp[n] = 1.

Any valid grouping must contain all numbers from 0 ... m-1.
We can keep track of the minimum positions of these numbers we have
encountered so far.

Let x be the maximum of these values. This is the first possible ending
position of the first group. Any grouping after this will be valid, so
dp[i] = sum(j=x+1, n) dp[j].

We can use a suffix array to speed this calculation up.

The final answer will be dp[0].
*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    set<int> s(a.begin(), a.end());
    int mex = 0;
    while(s.count(mex)){
        ++mex;
    }


    vector<int> dp(n+1);
    vector<int> suf(n+1);
    dp[n] = suf[n] = 1;

    vector<int> first(mex, -1);
    set<int> seen;

    int i = n-1;
    if(mex != 0){
        while(true){
            if(first[a[i]] != -1){
                seen.erase(seen.find(first[a[i]]));
            }
            first[a[i]] = i;
            seen.insert(i);

            suf[i] = 1;

            if((int)seen.size() == mex) break;

            --i;
        }
    }

    for(; i >= 0; --i){
        if(mex != 0){
            seen.erase(seen.find(first[a[i]]));
            first[a[i]] = i;
            seen.insert(i);
        }

        int maxind;
        if(mex==0) maxind = i;
        else{
            maxind = *(--seen.end());
        }
        dp[i] = suf[maxind+1];
        suf[i] = (suf[i+1] + dp[i]) % MOD;
    }

    cout << dp[0] << "\n";
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
