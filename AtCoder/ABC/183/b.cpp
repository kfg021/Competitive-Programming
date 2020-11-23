/*
Let the first point be (a, b), the second be (c, d), the turning point be
(a+x, 0), and theta be the angle of incidence. 
We can write the system of equations:
    x = b tan(theta)
    (c-a) - x = d tan(theta)

Solving this system gives x = b(c-a)/(b+d).
The answer will be x+a.
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ld ans = a + (ld)(b*(c-a))/(b+d);
    cout << fixed << setprecision(9) << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}