/*
If all values of the array are equal, there is no answer. Otherwise, the
answer exists. Consider the maximum element(s) of the array. Assuming not
all elements are the same, there can be at most n-1 of these elements.
Therefore, there must be at least one maximum that borders
a lesser element. We will take one of these values as our answer.
*/

#include <bits/stdc++.h> 
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    bool same = true;
    for(int i = 1; i < n; ++i){
        if(a[i]!=a[0]) same = false;
    }

    if(same){
        cout << "-1\n";
    }
    else{
        int mx = *max_element(a.begin(), a.end());
        for(int i = 0; i < n; ++i){
            if(a[i]==mx){
                if(i+1 < n && a[i] > a[i+1]){
                    cout << i+1 << "\n";
                    return;
                }
                if(i-1 >= 0 && a[i] > a[i-1]){
                    cout << i+1 << "\n";
                    return;
                }
            }
        }
        assert(false);
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