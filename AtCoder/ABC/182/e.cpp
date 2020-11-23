/*
Consider the horizontal and vertical illuminations seperatley. If we find
that a square is illuminated in either direction, then the answer will be yes
for that square. Considering only a single dimension, all squares between the
two boxes sorrounding a light source will be illuminated. Because of this, we
can relatively easily find the squares that should be illuminated.
*/

#include <bits/stdc++.h> 
using namespace std;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }

void solve(){
    int h, w, n, m;
    cin >> h >> w >> n >> m;
    vector<int> a(n), b(n), c(m), d(m);
    for(int i = 0; i < n; ++i){
        cin >> a[i] >> b[i];
        --a[i], --b[i];
    }
    for(int i = 0; i < m; ++i){
        cin >> c[i] >> d[i];
        --c[i], --d[i];
    }

    v2<bool> gr = fill(h, w, false);
    v2<bool> gc = gr;
    for(int i = 0; i < m; ++i){
        gr[c[i]][d[i]] = true;
        gc[c[i]][d[i]] = true;
    }

    for(int i = 0; i < n; ++i){
        int r = a[i];
        int c = b[i];
        
        int t = r;
        while(t >= 0 && !gr[t][c]){
            gr[t][c] = true;
            --t;
        }
        t = r+1;
        while(t < h && !gr[t][c]){
            gr[t][c] = true;
            ++t;
        }
    }

    for(int i = 0; i < n; ++i){
        int r = a[i];
        int c = b[i];
        
        int t = c;
        while(t >= 0 && !gc[r][t]){
            gc[r][t] = true;
            --t;
        }
        t = c+1;
        while(t < w && !gc[r][t]){
            gc[r][t] = true;
            ++t;
        }
    }

    int filled = 0;
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            filled += (gr[i][j] || gc[i][j]);
        }
    }
    cout << filled-m << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}