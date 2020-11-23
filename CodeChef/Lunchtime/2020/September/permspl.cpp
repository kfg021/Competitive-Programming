/*
This solution only works for Subtask 1, where n <= 16.
Since n is small, we can write a brute force algorithm. We will find all
possible ways the split the array into two parts, and calculate the number
of inversions in each part. This can be done efficiently using a bitmask
counting from 0 to 2^n - 1.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }
#define F first
#define S second

int inv(vector<int>& a){
    int n = a.size();
    int invs = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            if(a[i] > a[j]) ++invs;
        }
    }
    return invs;
}

void solve(){
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; ++i) cin >> p[i];

    for(int i = 0; i < (1<<n); ++i){
        vector<int> a, b;
        for(int j = 0; j < n; ++j){
            if((i>>j)&1){
                a.push_back(p[j]);
            }
            else{
                b.push_back(p[j]);
            }
        }

        if(inv(a)==inv(b)){
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
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
