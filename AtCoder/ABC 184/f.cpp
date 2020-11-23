/*
Notice that n <= 40 is slightly too big for a naive O(2^n) brute force
approach. This implies that a meet in the middle algorithm might be a
good idea.

Split the array into two halves. For each half, brute force the sum for
each possible subset. To combine these two half answers, we can iterate
through the first array, and binary search the greatest value b in the
second array that a+b <= t, where a is the current value in the first array.
The answer will be the maximium result over all a.

This reduces the complexity down to O(2^(n/2)), which runs fast enough 
since 2^20 is small.
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

vector<int> validsums(vector<int>& a, int t){
    int n = a.size();
    vector<int> all;
    for(int mask = 0; mask < 1<<n; ++mask){
        ll sum = 0;
        for(int i = 0; i < n; ++i){
            if(mask>>i & 1){
                sum += a[i];
            }
        }
        if(sum <= t){
            all.push_back(sum);
        }
    }
    return all;
}

void solve(){
    int n, t;
    cin >> n >> t;
    vector<int> a(n/2), b(n-n/2);
    for(int i = 0; i < n/2; ++i) cin >> a[i];
    for(int i = 0; i < n-n/2; ++i) cin >> b[i];

    vector<int> lans = validsums(a, t);
    vector<int> rans = validsums(b, t);

    int s = rans.size();
    sort(rans.begin(), rans.end());
    int ans = 0;
    for(int i : lans){
        int lo = 0;
        int hi = s-1;
        int best = 0;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(i+rans[mid] <= t){
                best = i+rans[mid];
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        ans = max(ans, best);
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}