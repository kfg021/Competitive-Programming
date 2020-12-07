/*
For the second part of the problem, we can use a similar approach as the first
part. We can group each square by both its diagonal. More formally, for each
filled square with coordinates (i, j), we place it in group (i+j)%3. Next, we
will change one of these groups to all X's, one to all O's, and leave the
last alone. Doing this will always result in a draw. There are six ways to
assign groups, so we will try them all. There will be at least one assignment
where we use <= floor(k/3) operations, using a similar argument to problem C1.
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

    string perm = "-OX";
    do{
        v2<char> gcpy = g;
        int ops = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(gcpy[i][j] != '.' && perm[(i+j)%3] != '-'){
                    if(gcpy[i][j] != perm[(i+j)%3]){
                        gcpy[i][j] = perm[(i+j)%3];
                        ++ops;
                    }
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
    }while(next_permutation(perm.begin(), perm.end()));

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