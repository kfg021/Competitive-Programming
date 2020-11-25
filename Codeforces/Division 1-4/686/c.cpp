/*
We can consider choosing each element as x. In each case, we will have to
remove all of the non-x elements. The number of operations needed will be
the number of gaps between the elements we wish to keep. We might also have
to do additional operations on the left and right sides of the array.
The answer will be the minimum over all possible x's.
*/

#include <bits/stdc++.h> 
using namespace std;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){
    return v2<T>(r, vector<T>(c, t));
}
#define F first
#define S second

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        --a[i];
    }

    v2<int> v(n);
    for(int i = 0; i < n; ++i){
        v[a[i]].push_back(i);
    }

    int ans = 1e9;
    for(vector<int>& keep : v){
        if(!keep.empty()){
            int s = keep.size();
            int score = 0;
            for(int i = 0; i < s-1; ++i){
                if(keep[i]+1 != keep[i+1]){
                    ++score;
                }
            }
            if(keep[0]!=0){
                ++score;
            }
            if(keep[s-1]!=n-1){
                ++score;
            }
            ans = min(ans, score);
        } 
    }
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