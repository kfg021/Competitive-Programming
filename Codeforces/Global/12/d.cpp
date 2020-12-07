/*
First consider special cases. For k = 1, we just need to check if the input
is a permutation. For k = n, we just need the array to contain 1.

For k = n-1, we need there to exist both 1 and 2. The two can exist anywhere,
but the 1 must be the leftmost or rightmost element of the array (and there
cannot be multiple occurrences). If any of these conditions were true, then there
will be two intervals containing a 1, and since min(1, 2) = 1, there answer will
be [1, 1] which is not a permutation. 

In fact, this can be generalized for all 2 <= k <= n-1. Consider some interval 
[l, r] initially equal to [0, n-1]. For k = x, we need x to exist somewhere in
the array, and we need to x-1 to only occur once, at either l or r. We also need
all x < k <= n to be valid. Our valid interval will shrink as we decrease k
(consider more elements in the permujtation).

We can iterate over x from [2, n-1], maintaining the interval [l, r] as we go.
*/

#include <bits/stdc++.h> 
using namespace std;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){
    return v2<T>(r, vector<T>(c, t));
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        --a[i];
    }

    v2<int> loc(n);
    for(int i = 0; i < n; ++i){
        loc[a[i]].push_back(i);
    }

    string s(n, '0');
    int l=0, r=n-1;
    for(int i = 0; i < n; ++i){
        if(i==0 && loc[i].size() != 0){
            s[n-1-i] = '1';
            continue;
        }

        //i exists and i-1 on edge
        if(loc[i].size() != 0){
            if(loc[i-1].size() == 1 && loc[i-1][0] == l){
                s[n-1-i] = '1';
                ++l;
            }
            else if(loc[i-1].size() == 1 && loc[i-1][0] == r){
                s[n-1-i] = '1';
                --r;
            }
            else{
                break;
            }
        }
        else{
            break;
        }
    }

    set<int> perm (a.begin(), a.end());
    if((int)perm.size() == n){
        s[0] = '1';
    }
    
    cout << s << "\n";
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