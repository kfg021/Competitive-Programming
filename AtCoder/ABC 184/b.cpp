/*
Simulate the process described in the statement. Iterate through the
string, adding one to the answer at every "o" character, subtracting
one at every "x" character (unless we are already at 0).
*/

#include <bits/stdc++.h> 
using namespace std;

void solve(){
    int n, x;
    string s;
    cin >> n >> x >> s;
    int ans = x;
    for(char c : s){
        if(c=='o') ++ans;
        else if(c=='x' && ans!=0) --ans;
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}