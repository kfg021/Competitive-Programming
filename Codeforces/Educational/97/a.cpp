/*
If r < 2l, the answer is YES. We can set a = 2l.
Otherwise, the answer is NO. We will prove this by contradiction.
Let's assume there exists a valid a. It must be true that a > 2l or a <= 2l.
a cannot be > 2l because l modulo (2l+x) = l, which is less than half of
2l+x (where x is positive). a cannot be <= 2l because we know that r >= 2l.
Therefore, there must be some number x in the range [l, r] such that x = a.
x modulo x is always 0, which is less than x/2 for all positive x.
Therefore such an a cannot exist, and the answer is NO when r >= 2l.
*/

#include <bits/stdc++.h> 
using namespace std;

void solve(){
    int l, r;
    cin >> l >> r;
    if(r < 2*l){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
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