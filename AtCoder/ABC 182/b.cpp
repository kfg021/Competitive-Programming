/*
We can solve this problem with a brute force that checks every possible
number from 2 to 1000. The number with the maximum score will be our answer.
*/

#include <bits/stdc++.h> 
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    int best = -1;
    int bestcnt = -1;
    for(int s = 2; s <= 1000; ++s){
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            if(a[i]%s == 0) ++cnt;
        }

        if(cnt > bestcnt){
            bestcnt = cnt;
            best = s;
        }
    }

    cout << best << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}