/* If we apply f(f(x)), we will obtain the original x, but with the trailing
zeros removed. Therefore g(x) = x / f(f(x)) = 10^(# of trailing zeros in x) .

Given that n has d digits, the answer is d. This is because we can always
produce at least one number with z trailing zeros that is <= n,
for all 0 <= z <= d-1 (For example, d-z ones followed by z zeros). This will
obtain all values of g from 0 to d-1.

So the answer is to print the number of digits in n.
*/

#include <bits/stdc++.h> 
using namespace std;

void solve(){
    string n;
    cin >> n;
    cout << (int)n.size() << "\n";
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