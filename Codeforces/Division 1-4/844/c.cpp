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
    string s;
    cin >> s;
    v2<int> loc_orig(26);
    for(int i = 0; i < n; i++){
        loc_orig[s[i]-'a'].push_back(i);
    }

    int ans = 1e9;
    string ans_t;

    for(int present = 1; present <= 26; present++){
        if(n % present == 0){
            auto loc = loc_orig;
            set<pair<int,int>, greater<pair<int,int>>> ss;
            for(int i = 0; i < 26; i++){
                if(!loc[i].empty()) ss.insert({(int)loc[i].size(), i});
            }

            vector<int> open;
            set<int> aval_chars;
            for(int i = 0; i < 26; i++) aval_chars.insert(i);

            int change = 0;
            string t(n, '?');

            int split = n/present;

            for(int char_num = 0; char_num < present; char_num++){
                int same, diff, use;
                if(ss.empty()){
                    same = 0;
                    diff = split;
                    use = *aval_chars.begin();
                }
                else{
                    auto begin = *ss.begin();
                    ss.erase(ss.begin());
                    same = min(begin.F, split);
                    diff = max(split-begin.F, 0);
                    use = begin.S;

                    for(int i = 0; i < same; i++){
                        t[loc[use].back()] = use+'a';
                        loc[use].pop_back();
                    }

                    begin.F -= same;
                    assert(begin.F >= 0);
                    for(int i : loc[begin.S]){
                        open.push_back(begin.S);
                    }
                }

                assert(aval_chars.count(use));
                aval_chars.erase(aval_chars.find(use));

                for(int i = 0; i < diff; i++){
                    if(!open.empty()){
                        assert(!loc[open.back()].empty());
                        t[loc[open.back()].back()] = use+'a';
                        loc[open.back()].pop_back();
                        open.pop_back();
                        change++;
                    }
                    else{
                        auto it = prev(ss.end());
                        auto end = *it;
                        ss.erase(it);
                        assert(!loc[end.S].empty());
                        t[loc[end.S].back()] = use+'a';
                        loc[end.S].pop_back();
                        change++;
                        end.F--;
                        if(end.F > 0){
                            ss.insert(end);
                        }
                    }      
                }
            }

            if(change < ans){
                ans = change;
                ans_t = t;
            }
        }
    }
    
    cout << ans << "\n";
    cout << ans_t << "\n";
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