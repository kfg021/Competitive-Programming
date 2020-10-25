/*
(Solved after contest).

First, construct an array of size 6n which contains a tuple (a[j]-b[i], i)
for all i from 0-(n-1) and all j from 0-5. Sort this array by the first
value. We will use a two-pointer approach to solve the problem. We will
iterate over the array, considering each index as a possible lower bound.
We increase the right pointer until we can find a valid subsection of the
array that contains at least one value for each n. The minimum value across
all subsections will be our final answer.
*/

#include <bits/stdc++.h> 
using namespace std;
#define F first
#define S second

void solve(){
    int n;
    vector<int> a(6);
    for(int i = 0; i < 6; ++i) cin >> a[i];
    cin >> n;
    vector<int> b(n);
    for(int i = 0; i < n; ++i) cin >> b[i];

    vector<pair<int, int>> notes;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 6; ++j){
            notes.push_back({b[i]-a[j], i});
        }
    }
    sort(notes.begin(), notes.end());

    int ans = 1e9+5;
    vector<int> have(n, 0);
    int need = n;
    int r = 0;
    ++have[notes[0].S];
    --need;
    for(int l = 0; l < 6*n; ++l){
        while(r+1 < 6*n && need > 0){
            ++r;
            if(!have[notes[r].S]){
                --need;
            }
            ++have[notes[r].S];
        }
        if(need > 0){
            break;
        }
        int score = notes[r].F-notes[l].F;
        ans = min(ans, score);

        --have[notes[l].S];
        if(!have[notes[l].S]){
            ++need;
        }
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}