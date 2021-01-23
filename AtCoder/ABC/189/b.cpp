/*
Iterate over the elements in order, stopping once our intake exceeds x.
To avoid using floating point, we will multiply all values by 100.
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

void solve(){
    int n,x;
    cin >> n >> x;
    vector<int> v(n), p(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i] >> p[i];
    }

    int ans = 0;
    x *= 100;
    for(int i = 0; i < n; ++i){
        ans += v[i]*p[i];
        if(ans > x){
            cout << i+1 << "\n";
            return;
        }
    }
    cout << "-1\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}