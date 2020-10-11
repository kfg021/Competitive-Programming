/*
This problem is relatively straightfoward. If the total sum of elements is 0,
the answer is NO. Otherwise the answer is YES. If the sum of elements is
positive, we can first take all positive elements and then all non-positive 
elements. If the sum is negative, we take negatives first and non-negatives second.
*/

#include <bits/stdc++.h> 
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    
    int sum = 0;
    for(int i = 0; i < n; ++i) sum += a[i];

    if(sum==0){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    if(sum>0){
        sort(a.begin(), a.end(), greater<int>());
    }
    else{
        sort(a.begin(), a.end());
    }

    for(int i : a) cout << i << " ";
    cout << "\n";
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