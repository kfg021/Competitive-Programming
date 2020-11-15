/*
Treat the x's and y's independently. For the y coordinates, the problem
essentially boils down to finding an integer a such that 
sum(i=0, n-1)(|y[i]-a|) is minimized. This is a well-known problem, and
it turns out that the median is the optimal answer. For the x coordinates,
we can do something similar. This time, we are trying to minimize
(sum i=0, n-1)(|x[i]-a-i)|). If we transform the x array by subtracting i
from all values x[i], we are solving the same problem. The final answer is
the combination of these two answers.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

ll dist(vector<int>& v){
    ll d = 0;
    int median = v[n/2];
    for(int i = 0; i < n; ++i){
        d += abs(median-v[i]);
    }
    return d;
}

void solve(){
    cin >> n;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; ++i){
        cin >> x[i] >> y[i];
    }

    sort(y.begin(), y.end());
    ll distv = dist(y);

    sort(x.begin(), x.end());
    for(int i = 0; i < n; ++i){
        x[i] -= i;
    }
    sort(x.begin(), x.end());
    ll disth = dist(x);

    ll ans = distv+disth;
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
