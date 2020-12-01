/*
Each player's goal is first maximize their score, then minimize the opponent's.
Bob can get maximum points by saving all of his stamina for when he gets
to serve (after Alice has run out of stamina).
The only exception is when Alice has only 1 stamina, in this case Bob
should return it, because he can also deny Alice 1 point.

Alice will make x serves, x-1 of which she wins (Bob returns the last one).
Bob will make 1 return and y-1 serves, winning all of them. 

Therefore, the answer is (x-1, y).
*/

#include <bits/stdc++.h> 
using namespace std;

void solve(){
    int x, y;
    cin >> x >> y;
    cout << x-1 << " " << y << "\n";
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