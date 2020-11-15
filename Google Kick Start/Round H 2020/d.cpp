/*
Two people are friends if they share a letter. From this, we can make
a graph over letters deonting which letters are connected to each other.
To solve the queries, we will perform a multiple source BFS starting from all 
letters in the first word. The answer will be the minimum distance to a
letter in the second word, plus 2.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }

vector<bool> allchars(string& ss){
    vector<bool> seen(26, false);
    for(char c : ss){
        seen[c-'A'] = true;
    }
    return seen;
}

void solve(){
    int n, q;
    cin >> n >> q;
    vector<string> s(n);
    v2<bool> adj = fill(26, 26, false);
    for(int i = 0; i < n; ++i){
        cin >> s[i];
    }

    v2<int> all(n);
    for(int i = 0; i < n; ++i){
        vector<bool> seen = allchars(s[i]);
        for(int c = 0; c < 26; ++c){
            if(seen[c]){
                all[i].push_back(c);
            }
        }
    }

    for(int i = 0; i < n; ++i){
        for(int x : all[i]){
            for(int y : all[i]){
                adj[x][y] = true;
            }
        }
    }

    for(int i = 0; i < q; ++i){
        int a, b;
        cin >> a >> b;
        --a, --b;

        queue<char> q;
        vector<bool> v(26, false);
        vector<int> d(26, -1);
        for(int c : all[a]){
            q.push(c);
            v[c] = true;
            d[c] = 0;
        }
        
        while(!q.empty()){
            int c = q.front();
            q.pop();
            for(int next = 0; next < 26; ++next){
                if(adj[c][next] && !v[next]){
                    v[next] = true;
                    d[next] = 1+d[c];
                    q.push(next);
                }
            }
        }

        int ans = 1e9;
        for(int c : all[b]){
            if(d[c]!=-1){
                ans = min(ans, d[c]);
            }
        }

        if(ans == 1e9){
            cout << "-1 ";
        }
        else{
            cout << ans+2 << " ";
        }
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for(int i = 1; i <= T; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}