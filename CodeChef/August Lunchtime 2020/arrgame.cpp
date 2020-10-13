/*
Lets consider the contigous reigons of 0's in the array. It is optimal
for the first player to make their first move in the center of the greatest
size reigon. If the this region has even length, player 1 will lose. If it is odd,
it depends on the size of the next largest reigon (if there is only one reigon,
then player 1 wins). Let a be the size of the largest reigon, and let b be the
size of the second largest. Player 1 will win if a/2+1 > b.
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    vector<int> g;
    bool ong = false;
    for(int i = 0; i < n; ++i){
        if(a[i]==0 && ong){
            ++g.back();
        }
        else if(a[i]==0){
            ong = true;
            g.push_back(1);
        } 
        else{
            ong = false;
        }  
    }

    sort(g.begin(), g.end(), greater<int>());
    if(g.empty()){
        cout << "No\n";
    }
    else if(g[0]%2==0){
        cout << "No\n";
    }
    else if(g.size() >= 2){
        if(g[0]/2+1 > g[1]) cout << "Yes\n";
        else cout << "No\n";
    }
    else{
        cout << "Yes\n";
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
