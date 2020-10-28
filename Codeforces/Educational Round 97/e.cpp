/*
Let's transform the original array a to a', where a'[i] = a[i]-i.
Because of this transformation, being increasing in a is the same as
being non-decreasing in a'. Consider each portion of the array that we
are allowed to modify seperately (between adjacent pairs of b values).
Let s be the segment, and let l be the length of s. Since we cannot change
the boundaries, let min and max represent the minimum and maximum values
we are allowed to use. If min > max, the answer will be -1.
Otherwise, the answer for s will be:
    l - (the longest non-decreasing subsequence of s such that all
    elements are >= min and <= max).

Sum up this value over all segments to obtain the final answer. 
*/

#include <bits/stdc++.h> 
using namespace std;

const int INF = 1e9+5;

vector<int> a, b;

int lnds(int l, int r, int mn, int mx){
    int s = r-l+1;
    vector<int> best(s, INF);
    for(int i = l; i <= r; ++i){
        if(a[i]>=mn && a[i]<=mx){
            int lo = 0;
            int hi = s-1;
            int ans = -1;
            while(lo<=hi){
                int mid = (lo+hi)/2;
                if(a[i]<best[mid]){
                    ans = mid;
                    hi = mid-1;
                }
                else{
                    lo = mid+1;
                }
            }
            best[ans] = a[i];
        }
    }

    for(int i = s-1; i >= 0; --i){
        if(best[i]!=INF){
            return i+1;
        }
    }
    return 0;
}

void solve(){
    int n, k;
    cin >> n >> k;
    a = vector<int>(n+2), b = vector<int>(k+2);

    a[0] = -INF, a[n+1] = INF;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        a[i] -= i;
    }
    b[0] = 0, b[k+1] = n+1; 
    for(int i = 1; i <= k; ++i){
        cin >> b[i];
    }

    int ans = 0;
    for(int i = 0; i < k+1; ++i){
        int l = b[i], r = b[i+1];
        if(a[l]>a[r]){
            cout << "-1\n";
            return;
        }

        int s = r-l-1;
        ans += s - lnds(l+1, r-1, a[l], a[r]);
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}