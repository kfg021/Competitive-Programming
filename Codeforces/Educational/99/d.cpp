/*
We can use a greedy approach where we always choose the smallest i such that
a[i] > x to swap. In each iteration, we check if we have successfully sorted the
array. If we reach the end of the array without sorting, the answer is -1.

Since a[i] > x holds for every i we swap, the values of x are strictly increasing,
From this, one can prove that we will make at most n swaps, keeping the time
complexity at O(n^2).
*/

#include <bits/stdc++.h> 
using namespace std;

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    int ans = 0;
    while(true){
        if(is_sorted(a.begin(), a.end())){
            cout << ans << "\n";
            return;
        }
        int first = 0;
        while(first < n && a[first] <= x){
            ++first;
        }
        if(first == n){
            cout << "-1\n";
            return;
        }
        else{
            swap(x, a[first]);
        }
        ++ans;
    }
    assert(false);
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