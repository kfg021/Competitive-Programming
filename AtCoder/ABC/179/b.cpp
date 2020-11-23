/*
Pretty self-explanatory; implements what is asked in the problem.
*/

#include <bits/stdc++.h> 
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i] >> b[i];

    int cnt = 0;
    for(int i = 0; i < n; ++i){
        if(a[i]==b[i]){
            ++cnt;
        }
        else{
            cnt = 0;
        }

        if(cnt>=3){
            cout << "Yes\n";
            return;
        }
    }

    cout << "No\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}