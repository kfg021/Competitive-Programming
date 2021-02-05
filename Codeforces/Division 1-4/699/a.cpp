/*
Assume that a,b >= 0. In this case we need at least a U's and b R's.
We can delete all other moves that do not help us. The same logic can
be applied for all a,b (swapping U/D and L/R depending on the sign of a,b)
*/

#include <bits/stdc++.h> 
using namespace std;

void solve(){
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;

    char x, y;
    if(a >= 0) x = 'R';
    else x = 'L';

    if(b >= 0) y = 'U';
    else y = 'D';

    int amtx=0, amty=0;
    for(char c : s){
        if(c==x) ++amtx;
        else if(c==y) ++amty;
    }

    if(amtx >= abs(a) && amty >= abs(b)){
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