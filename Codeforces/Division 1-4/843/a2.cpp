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
    string s;
    cin >> s;
    int n = s.size();

    int b = 0;
    for(char c : s){
        b += (c=='b');
    }

    int firsta = -1, lasta = -1;
        for(int i = 0; i < n; i++){
            if(s[i]=='a'){
                lasta = i;
                if(firsta == -1) firsta = i;
            }
        }

    int firstb = -1, lastb = -1;
        for(int i = 0; i < n; i++){
            if(s[i]=='b'){
                lastb = i;
                if(firstb == -1) firstb = i;
            }
        }

    if(b == 0 || b == n){
        cout << s[0] << " " << s.substr(1, n-2) << " " << s[n-1] << "\n";
    }
    else if(s[0] == 'b' && s[n-1]=='b'){
        string a, b, c;
        for(int i = 0; i < n; i++){
            if(i < firsta){
                a += s[i];
            }
            else if(i <= lasta){
                b += s[i];
            }
            else{
                c += s[i];
            }
        }
        cout << a << " " << b << " " << c << "\n";
    }
    else if(s[0]=='a'){
        if(firstb == lastb){
            cout << s.substr(0, n-2) << " " << s[n-2] << " " << s[n-1] << "\n";
        }
        else{
            int cur = 0;
            vector<string> v(3);
            for(int i = 0; i < n; i++){
                if(cur==0 && s[i]=='b'){
                    cur = 1;
                }
                else if(cur == 1 && s[i] == 'a'){
                    cur = 2;
                }
                v[cur] += s[i];
            }
            if(v[2].empty()){
                v[2] += v[1].back();
                v[1].pop_back();
            }

            cout << v[0] << " " << v[1] << " " << v[2] << "\n";
        }
    }
    else if(s[0]=='b'){
        if(firsta == lasta){
            cout << s[0] << " " << s.substr(1, n-2) << " " << s[n-1] << "\n";
        }
        else{
            string a, b, c;
            for(int i = 0; i < n; i++){
                if(i < firsta) a += s[i];
                else if(i == firsta){
                    b += s[i];
                }
                else{
                    c += s[i];
                }
            }

            cout << a << " " << b << " " << c << "\n";
        }
    }
    else{
        string a, b, c;
        for(int i = 0; i < n; i++){
            if(i < firstb){
                a += s[i];
            }
            else if(i <= lastb){
                b += s[i];
            }
            else{
                c += s[i];
            }
        }
        cout << a << " " << b << " " << c << "\n";
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