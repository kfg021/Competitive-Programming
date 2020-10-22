/*
We know the number of digits pressed in one round will be
1+2+3+4 = (4*5)/2 = 10. We can use any digit of x to determine the
number of full rounds. After that, we can use the number of digits in x to
find the final answer. The answer will be 10*(d-1) + n*(n+1)/2, where n is the
number of digits in x, and d is the value of one of x's digits.
*/

#include <bits/stdc++.h> 
using namespace std;

void solve(){
    string x;
    cin >> x;
    int n = x.size();

    int ans = 0;
    int before = (x[0]-'0')-1;
    
    ans += before*10;
    ans += (n*(n+1))/2;
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