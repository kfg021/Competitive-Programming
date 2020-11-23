/*
Implement what is asked in the problem statement. Be careful to never
print a negative answer.
*/

#include <bits/stdc++.h> 
using namespace std;

void solve(){
    int a, b;
    cin >> a >> b;
    int c = 2*a+100;
    int ans = max(0, c-b);
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}