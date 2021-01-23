/*
Two unit vectors uniquely define a 2-dimensional coordinate space.
We can represent these vectors using three points: the origin (starting
point for both vectors) and the vectors' endpoints.
These points are initially set to (0, 0), (1, 0), and (1, 0) respectively.

We can determine the location of an arbitrary point after some operations
by tracking the location these three points and using them to construct the
unit vectors of the transformed coordinate space.
*/

#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){
    return v2<T>(r, vector<T>(c, t));
}

struct point{
    ll x, y;
};
point operator+(const point& a, const point& b){
    return {a.x + b.x, a.y + b.y};
}
point operator-(const point& a, const point& b){
    return {a.x - b.x, a.y - b.y};
}
point operator*(int a, const point& p){
    return {a * p.x, a * p.y};
}

point rot_cw(point& p){
    return {p.y, -p.x};
}
point rot_ccw(point& p){
    return {-p.y, p.x};
}

point ref_x(point& p, int a){
    return {2*a - p.x, p.y};
}
point ref_y(point& p, int a){
    return {p.x, 2*a - p.y};
}

void solve(){
    int n, m, q;

    cin >> n;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; ++i){
        cin >> x[i] >> y[i];
    }

    cin >> m;
    v2<point> basis = fill(m+1, 3, point{-1, -1});
    basis[0] = {{0, 0}, {1, 0}, {0, 1}};
    for(int i = 0; i < m; ++i){
        int a;
        cin >> a;
        if(a == 1){
            for(int j = 0; j < 3; ++j){
                basis[i+1][j] = rot_cw(basis[i][j]);
            }
        }
        else if(a == 2){
            for(int j = 0; j < 3; ++j){
                basis[i+1][j] = rot_ccw(basis[i][j]);
            }
        }
        else if(a == 3){
            int b;
            cin >> b;
            for(int j = 0; j < 3; ++j){
                basis[i+1][j] = ref_x(basis[i][j], b);
            }
        }
        else{
            int b;
            cin >> b;
            for(int j = 0; j < 3; ++j){
                basis[i+1][j] = ref_y(basis[i][j], b);
            }
        }
    }

    cin >> q;
    for(int i = 0; i < q; ++i){
        int a, b;
        cin >> a >> b;
        --b;

        point origin = basis[a][0];
        point i_hat = basis[a][1] - basis[a][0];
        point j_hat = basis[a][2] - basis[a][0];
        
        point ans = origin + (x[b] * i_hat) + (y[b] * j_hat);
        cout << ans.x << " " << ans.y << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}