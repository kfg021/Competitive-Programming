/*
There are O(log_x(n)) powers of x less than or equal to n, so we can
calculate them all very quickly. Then, we brute force all possible pairs
to see if they are equal to our desired sum.

Be careful not to overflow.
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

void solve(){
    ll n;
    cin >> n;

    ll MX = 1e18+5;

    vector<ll> p3, p5;
    p3.push_back(1);
    p5.push_back(1);
    while(p3.back() <= MX/3LL){
        p3.push_back(p3.back()*3LL);
    }
    while(p5.back() <= MX/5LL){
        p5.push_back(p5.back()*5LL);
    }

    for(int i = 1; i < (int)p3.size(); ++i){
        for(int j = 1; j < (int)p5.size(); ++j){
                if(n==p3[i]+p5[j]){
                    cout << i << " " << j << "\n";
                    return;
                }
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