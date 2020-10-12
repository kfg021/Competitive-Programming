/*
The answer will always be either 0, 1, or 2.
The answer is 0 if all ratings are equal to x at the start.
The answer will be 1 if there is at least one infected account
at the start, or the sum(i=0 n-1)(a[i]-x) = 0.
Otherwise, the answer is 2.
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

void solve(){
    int n, x;
    cin >> n>>x;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    bool eq = true;
    for(int i = 0; i < n; ++i){
        if(a[i]!=x) eq=false;
    }

    if(eq){
        cout << "0\n";
    }
    else{
        bool same = false;
        ll sum = 0;
        for(int i = 0; i < n; ++i){
            if(a[i]==x) same=true;
            sum += x-a[i];
        }
        if(sum==0 || same){
            cout << "1\n";
        }
        else{
            cout << "2\n";
        }
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