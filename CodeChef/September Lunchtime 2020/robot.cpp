/*
This is a constructive problem, so there are obviously many different
appraches. My approach works by always ensuring that the robot lands
directly above the obstacle. The first sequence of moves moves the robot
to a location above the obstacle, but one column to the right. We then move the robot 
it right one unit, and move it down far enough such that it hits the
obstacle and gets stuck.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }
#define F first
#define S second

void solve(){
    int r, c;
    cin >> r >> c;

    string ans;
    for(int i = 0; i < r+1; ++i){
        ans += 'U';
        for(int j = 0; j < c; ++j){
            ans += 'R';
        }
        if(i != r){
            for(int j = 0; j < c; ++j){
                ans += 'L';
            }
        }
    }

    ans += 'R';
    for(int i = 0; i < r+5; ++i){
        ans += 'D';
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
