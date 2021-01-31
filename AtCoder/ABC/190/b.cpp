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
    int n, s, d;
    cin >> n >> s >> d;

    bool good = false;
    for(int i =  0; i < n; ++i){
        int x, y;
        cin >> x >> y;

        if(x < s && y > d){
            good = true;
        }
    }

    if(good){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}