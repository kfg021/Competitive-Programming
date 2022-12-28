#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){
    return v2<T>(r, vector<T>(c, t));
}
#define F first
#define S second

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> b(n*m);
    for(int i = 0; i < n*m; i++){
        cin >> b[i];
    }
    sort(b.begin(), b.end());

    int x = min(n, m);
    // need ceil((x-1)/2) below and floor((x-1)/2) above
    int below = x/2;
    int above = (x-1)/2;
    int path = n+m-1;
    assert(below+path+above <= n*m);

    int beststart = -1;
    int bestend = -1;
    int bot = below;
    int top = n*m-1-above;
    for(int i = 0; i < n*m; i++){
        int j = i + path-1;
        if(i >= bot && j <= top){
            if(beststart == -1 || (b[j]-b[i] < b[bestend]-b[beststart])){
                beststart = i;
                bestend = j;
            }
        }
    }

    vector<int> vbelow, vpath, vabove;
    for(int i = 0; i < n*m; i++){
        if(i < beststart){
            vbelow.push_back(b[i]);
        }
        else if(i >= beststart && i <= bestend){
            vpath.push_back(b[i]);
        }
        else{
            vabove.push_back(b[i]);
        }
    }

    v2<int> ans = fill(n, m, -1);
    if(n >= m){
        for(int j = 0; j < m-1; j++){
            if(j%2 == 0){
                ans[1][j] = vbelow.back();
                vbelow.pop_back();
            }
            else{
                ans[1][j] = vabove.back();
                vabove.pop_back();
            }
        }

        for(int j = 0; j < m; j++){
            ans[0][j] = vpath.back();
            vpath.pop_back();
        }
        for(int i = 1; i < n; i++){
            ans[i][m-1] = vpath.back();
            vpath.pop_back();
        } 
    }
    else{
        for(int i = 0; i < n-1; i++){
            if(i%2 == 0){
                ans[i][1] = vbelow.back();
                vbelow.pop_back();
            }
            else{
                ans[i][1] = vabove.back();
                vabove.pop_back();
            }
        }

        for(int i = 0; i < n; i++){
            ans[i][0] = vpath.back();
            vpath.pop_back();
        }
        for(int j = 1; j < m; j++){
            ans[n-1][j] = vpath.back();
            vpath.pop_back();
        }
    }

    assert(vpath.empty());
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(ans[i][j] == -1){
                if(!vbelow.empty()){
                    ans[i][j] = vbelow.back();
                    vbelow.pop_back();
                }
                else{
                    assert(!vabove.empty());
                    ans[i][j] = vabove.back();
                    vabove.pop_back();
                }
            }
        }
    }

    assert(vabove.empty());
    assert(vbelow.empty());

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
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
