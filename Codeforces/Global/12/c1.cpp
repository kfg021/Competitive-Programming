/*
In the first part of the problem, we know that all squares are either X's
or blank. In this case, it suffices to change every 3rd diagonal to an O.
We just need to be careful to choose the right diagonals to change so that
we don't use more than floor(k/3) operations. We can just check all three
possibilities and choose one that works. One will always work since for any
a+b+c = k, min(a, b, c) <= floor(k/3).
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
    int k = 0;
    v2<char> g = fill(n, n, '?');
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> g[i][j];
            if(g[i][j] != '.') ++k;
        }
    }

    for(int off = 0; off < 3; ++off){
        v2<char> gcpy = g;
        int ops = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if((i+j+off)%3 == 0 && gcpy[i][j] == 'X'){
                    gcpy[i][j] = 'O';
                    ++ops;
                }
            }
        }
        if(ops <= k/3){
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j){
                    cout << gcpy[i][j];
                }
                cout << "\n";
            }
            return;
        }
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