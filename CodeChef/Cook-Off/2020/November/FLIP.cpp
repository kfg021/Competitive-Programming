/*
We can treat flipping even and odd substrings as independent operations.
Define two arrays, even and odd such that
    even[i] := {1 if a[2i]!=b[2i], 0 otherwise}
    odd[i] := {1 if a[2i+1]!=b[2i+1], 0 otherwise}

In order to convert a to b, we must remove all 1's in both arrays. In one
operation, we can change a continous range of 1's to 0's. To figure out the
number of operations, we can count the number of contigious ranges of 1's in
both the even and odd arrays, and sum the results. 
*/

#include <bits/stdc++.h>
using namespace std;

int groups(vector<bool>& a){
    vector<int> g;
    int n = a.size();
    for(int i = 0; i < n; ++i){
        if(a[i]){
            if(g.empty() || i-g.back() > 1){
                g.push_back(i);
            }
            else{
                ++g.back();
            }
        }
    }
    return g.size();
}

void solve(){
    string a, b;
    cin >> a >> b;
    int n = a.size();

    vector<bool> even, odd;
    for(int i = 0; i < n; ++i){
        if(i%2==0){
            even.push_back(a[i]!=b[i]);
        }
        else{
            odd.push_back(a[i]!=b[i]);
        }
    }

    int ans = groups(even) + groups(odd);
    cout << ans << "\n";
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
