/*
If there exists a ball such that all other balls are a manhattan distance
<= k away, the answer is 1. Otherwise, the answer is -1. 

To see why this is, consider some center c (the final position). If we perform
the operation on c, we will attract all of the balls of distance <= k, making
it impossible to retrieve the balls of distance > k. To attract these balls, we
will eventually need to the operation on some ball within a distance k of c.
However, this operation will move c itself, violating our assumption that c
is the center. By contradiction, there cannot exist such a c, and so the
answer is -1.
*/

#include <bits/stdc++.h> 
using namespace std;
#define F first
#define S second

int manh(pair<int,int>& a, pair<int,int>& b){
    return abs(a.F-b.F) + abs(a.S-b.S);
}

void solve(){
    int n, k;
    cin >> n >> k;

    vector<pair<int,int>> x(n);
    for(int i = 0; i < n; ++i){
        cin >> x[i].F >> x[i].S;
    }

    for(int cent = 0; cent < n; ++cent){
        bool good = true;
        for(int i = 0; i < n; ++i){
            if(manh(x[cent], x[i]) > k){
                good = false;
            }
        }
        if(good){
            cout << "1\n";
            return;
        }
    }
    cout << "-1\n";
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