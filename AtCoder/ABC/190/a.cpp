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
    int a, b, c;
    cin >> a >> b >> c;
    if(a < b){
        cout << "Aoki\n";
    }
    else if(b < a){
        cout << "Takahashi\n";
    }
    else if(c==0){
        cout << "Aoki\n";
    }
    else{
        cout << "Takahashi\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}