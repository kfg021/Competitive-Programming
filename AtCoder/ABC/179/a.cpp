/*
Pretty self-explanatory; implements what is asked in the problem.
*/

#include <bits/stdc++.h> 
using namespace std;

void solve(){
    string s;
    cin >> s;
    if(s[(int)s.length()-1]=='s'){
        s += "es";
    }
    else{
        s += "s";
    }

    cout << s << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}