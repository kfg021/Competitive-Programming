/*
We can store a set containing all strings. Then, we can easily check whether
some string s and the string ("!" + s) both exist. If so, the SAT is unsatisfiable.
*/

#include <bits/stdc++.h> 
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; ++i){
        cin >> s[i];
    }

    set<string> seen(s.begin(), s.end());
    for(int i = 0; i < n; ++i){
        if(s[i][0] != '!'){
            if(seen.count("!" + s[i])){
                cout << s[i] << "\n";
                return;
            }
        }
    }

    cout << "satisfiable\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}