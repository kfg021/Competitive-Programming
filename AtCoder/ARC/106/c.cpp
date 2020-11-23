/*
It can be proven that Takahashi's algorithm is optimal. Therefore, his
answer will always greater than or equal to Aoki's answer. If m is negative,
the answer will be -1.

Otherwise, we will try to construct a valid answer. The reason that Aoki's
algorithm is nonoptimal is because it may choose large intervals that
start early but end late. We will take advantage of this fact by creating
a large interval starting at 1. We will place m+1 smaller intervals in
between this large interval. This way, Takahashi will get the m+1
intervals, while Aoki will only get the large one. The difference will be
m+1 - 1 = m. We might have used more than n intervals to construct this, in
which case the answer will be -1. Otherwise, place the remaining intervals
such that they do not overlap with any of the other intervals.
*/

#include <bits/stdc++.h> 
using namespace std;
#define F first
#define S second

void solve(){
    int n, m;
    cin >> n >> m;

    if(m<0){
        cout << "-1\n";
        return;
    }

    vector<pair<int, int>> ans;
    int used = 0;
    if(m!=0){
        ans.push_back({1, 1e6});
        ++used;
        for(int i = 0; i < m+1; ++i){
            ans.push_back({i*2+2, i*2+3});
            ++used;
        }
    }
    if(used > n){
        cout << "-1\n";
        return;
    }
    int last = 1e6+5;
    while(used < n){
        ans.push_back({last, last+1});
        last += 2;
        ++used;
    }
    
    for(auto a : ans){
        cout << a.F << " " << a.S << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}