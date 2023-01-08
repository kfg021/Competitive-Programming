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
    int n;
    cin >> n;

    vector<int> ans(n*n);
    deque<int> next;
    for(int i = 1; i <= n*n; i++){
        next.push_back(i);
    }
    for(int i = 0; i < n*n; i++){
        if(i%2 == 0){
            ans[i] = next.front();
            next.pop_front();
        }
        else{
            ans[i] = next.back();
            next.pop_back();
        }
    }

    for(int i = 0; i < n; i++){
        if(i%2 == 0){
            for(int j = 0; j < n; j++){
                cout << ans[i*n + j] << " ";
            }
        }
        else{
            for(int j = n-1; j >= 0; j--){
                cout << ans[i*n + j] << " ";
            }
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